/*
 * Copyright 2026 NWChemEx-Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** @file uq_factory.hpp
 *
 * Defines simde::UQFactory, the result type of the UQInitializer property
 * type (declared in uq_initializer.hpp).
 */
#pragma once
#include <memory>
#include <stdexcept>
#include <string>
#include <tensorwrapper/tensorwrapper.hpp>
#include <type_traits>

namespace simde {

/** @brief The UQ representations UQInitializer knows how to build a factory
 *         for.
 *
 *  `none` is plain `double`, i.e., no uncertainty. It lets a module that
 *  creates values from `double` values be told not to make them uncertain.
 */
enum class UQKind { none, uncertain, interval, affine, thresholded_affine };

/** @brief Parses a "UQ Type" module-input string into a UQKind.
 *
 *  This is the single place the accepted "UQ Type" string literals are
 *  spelled out; UQInitializer and UQAtomSymmBlockedDriver's tests both rely
 *  on this mapping staying in sync with UQFactory's construction logic.
 *
 *  @throw std::runtime_error if @p uq_type does not match a known UQ kind.
 */
inline UQKind uq_kind_from_string(const std::string& uq_type) {
    if(uq_type == "none") return UQKind::none;
    if(uq_type == "uncertain") return UQKind::uncertain;
    if(uq_type == "interval") return UQKind::interval;
    if(uq_type == "affine") return UQKind::affine;
    if(uq_type == "thresholded affine") return UQKind::thresholded_affine;
    throw std::runtime_error(
      "simde::uq_kind_from_string: Invalid UQ type name " + uq_type);
}

/// Inverse of uq_kind_from_string, kept alongside it for symmetry/debugging.
inline std::string to_string(UQKind kind) {
    switch(kind) {
        case UQKind::none: return "none";
        case UQKind::uncertain: return "uncertain";
        case UQKind::interval: return "interval";
        case UQKind::affine: return "affine";
        case UQKind::thresholded_affine: return "thresholded affine";
    }
    throw std::runtime_error("simde::to_string(UQKind): Unrecognized UQKind");
}

/** @brief Polymorphic base class for constructing a UQ scalar from a center
 *         and a radius.
 *
 *  The UQFactorBase class is used as a PIMPL for UQFactory (below) so that
 *
 *  Each UQ representation (sigma::Uncertain, sigma::Interval, sigma::Affine,
 *  sigma::ThresholdedAffine) is an independent template
 *  class with no shared base in `sigma`/`tensorwrapper` (they're unified only
 *  by compile-time traits). This class supplies the runtime-polymorphic base
 *  UQInitializer needs so it can hand back "a factory for whichever UQ kind
 *  the caller asked for" as a single result type, and so downstream code
 *  (UQAtomSymmBlockedDriver's Kernel) can construct UQ values without a
 *  compile-time dependence on which kind was selected.
 *
 *  N.b., only `double` centers/radii are supported at present. If/when needed
 *  the API could be extended to other types.
 */
class UQFactoryBase {
public:
    /// Virtual dtor
    virtual ~UQFactoryBase() = default;

    /// Constructs a UQ scalar of *this's kind, centered at @p center with
    /// radius @p radius, type-erased into a wtf::fp::Float.
    virtual wtf::fp::Float operator()(double center, double radius) const = 0;

    /// Identifies which UQ representation *this constructs.
    virtual UQKind kind() const noexcept = 0;

    /// Deep-copies *this. Kept for forward compatibility even though
    /// UQFactory (below) uses shared, not owning, copies.
    virtual std::unique_ptr<UQFactoryBase> clone() const = 0;

    /// True if *this and @p rhs would construct value-equal UQ scalars.
    virtual bool equal(const UQFactoryBase& rhs) const noexcept {
        return kind() == rhs.kind();
    }

    /// Imposes a strict weak ordering, for PluginPlay's AnyField.
    virtual bool less(const UQFactoryBase& rhs) const noexcept {
        return kind() < rhs.kind();
    }
};

namespace detail {

/// Implements UQFactory for UQKind::none, which drops the radius
class NoneFactoryImpl final : public UQFactoryBase {
public:
    /// Returns @p center as a double. @p radius is ignored.
    wtf::fp::Float operator()(double center, double) const override {
        return wtf::fp::Float(center);
    }

    /// Returns UQKind::none.
    UQKind kind() const noexcept override { return UQKind::none; }

    /// Returns a deep-copy of *this.
    std::unique_ptr<UQFactoryBase> clone() const override {
        return std::make_unique<NoneFactoryImpl>(*this);
    }
};

/// Implements UQFactory for all UQ kinds except none.
template<UQKind Kind, template<typename> typename UQType>
class SimpleFactoryImpl final : public UQFactoryBase {
public:
    /// Dispatches to tensorwrapper::types::construct_uq_type<UQType>
    wtf::fp::Float operator()(double center, double radius) const override {
        return wtf::fp::Float(
          tensorwrapper::types::construct_uq_type<UQType<double>>(center,
                                                                  radius));
    }

    /// Returns the UQKind template parameter.
    UQKind kind() const noexcept override { return Kind; }

    /// Returns a deep-copy of *this.
    std::unique_ptr<UQFactoryBase> clone() const override {
        return std::make_unique<SimpleFactoryImpl>(*this);
    }
};

/// Convenience aliases for the 4 SimpleFactoryImpl specializations.
using UncertainFactoryImpl =
  SimpleFactoryImpl<UQKind::uncertain, tensorwrapper::types::uncertain_type>;
using IntervalFactoryImpl =
  SimpleFactoryImpl<UQKind::interval, tensorwrapper::types::interval_type>;
using AffineFactoryImpl =
  SimpleFactoryImpl<UQKind::affine, tensorwrapper::types::affine_type>;
using ThresholdedAffineFactoryImpl =
  SimpleFactoryImpl<UQKind::thresholded_affine,
                    tensorwrapper::types::thresholded_affine_type>;

} // namespace detail

/** @brief A copyable, comparable factory for constructing UQ values of a
 *         caller-configured kind.
 *
 *  This is the public API for creating UQ Forms without needing to know what
 *  kind of UQ Form is being created
 *
 *  This class wraps one in a std::shared_ptr<const UQFactoryBase>: copies are
 *  shallow (the underlying Impl is immutable after construction), giving
 *  cheap value semantics without deep-cloning on every copy.
 */
class UQFactory {
public:
    /// Defaults to an "uncertain" factory so PluginPlay's requirement that
    /// results be default constructible is met without a null state.
    UQFactory() : m_impl_(std::make_shared<detail::UncertainFactoryImpl>()) {}

    /// Constructs a factory for the UQ kind specified by @p kind.
    explicit UQFactory(UQKind kind) : m_impl_(make_impl_(kind)) {}

    /// Main API for building the UQ value
    wtf::fp::Float operator()(double center, double radius) const {
        return (*m_impl_)(center, radius);
    }

    /// Returns the UQKind *this will build
    UQKind kind() const noexcept { return m_impl_->kind(); }

    /// True if *this and @p rhs would build value-equal UQ scalars.
    bool operator==(const UQFactory& rhs) const noexcept {
        return m_impl_->equal(*rhs.m_impl_);
    }

    /// Imposes a strict weak ordering
    bool operator<(const UQFactory& rhs) const noexcept {
        return m_impl_->less(*rhs.m_impl_);
    }

private:
    static std::shared_ptr<const UQFactoryBase> make_impl_(UQKind kind) {
        switch(kind) {
            case UQKind::none:
                return std::make_shared<detail::NoneFactoryImpl>();
            case UQKind::uncertain:
                return std::make_shared<detail::UncertainFactoryImpl>();
            case UQKind::interval:
                return std::make_shared<detail::IntervalFactoryImpl>();
            case UQKind::affine:
                return std::make_shared<detail::AffineFactoryImpl>();
            case UQKind::thresholded_affine:
                return std::make_shared<detail::ThresholdedAffineFactoryImpl>();
        }
        throw std::runtime_error("simde::UQFactory: Unrecognized UQKind");
    }

    std::shared_ptr<const UQFactoryBase> m_impl_;
};

/** @brief Calls @p visitor with the floating-point type @p kind names.
 *
 *  UQFactory builds type-erased values. Modules which fill a buffer of a
 *  compile-time type use this function to turn the run-time kind of a factory
 *  into that type, *e.g.*,
 *
 *  @code
 *  auto t = visit_uq_kind(factory.kind(), [&](auto type) {
 *      using float_type = typename decltype(type)::type;
 *      return fill_tensor<float_type>(...);
 *  });
 *  @endcode
 *
 *  @tparam FloatType The floating-point type the uncertain types are built
 *                    on, and the type used for UQKind::none. Defaults to
 *                    double.
 *  @tparam VisitorType The type of the visitor. Must be callable with
 *                      std::type_identity<T> for each type T, and return the
 *                      same type for each.
 *
 *  @param[in] kind The UQ kind to dispatch on.
 *  @param[in] visitor The callable to call.
 *
 *  @return Whatever @p visitor returns.
 *
 *  @throw std::runtime_error if @p kind is not a known UQKind. Strong throw
 *                            guarantee.
 *  @throw ??? if @p visitor throws. Same throw guarantee.
 */
template<typename FloatType = double, typename VisitorType>
decltype(auto) visit_uq_kind(UQKind kind, VisitorType&& visitor) {
    using namespace tensorwrapper::types;
    switch(kind) {
        case UQKind::none: return visitor(std::type_identity<FloatType>{});
        case UQKind::uncertain:
            return visitor(std::type_identity<uncertain_type<FloatType>>{});
        case UQKind::interval:
            return visitor(std::type_identity<interval_type<FloatType>>{});
        case UQKind::affine:
            return visitor(std::type_identity<affine_type<FloatType>>{});
        case UQKind::thresholded_affine:
            return visitor(
              std::type_identity<thresholded_affine_type<FloatType>>{});
    }
    throw std::runtime_error("simde::visit_uq_kind: Unrecognized UQKind");
}

} // namespace simde

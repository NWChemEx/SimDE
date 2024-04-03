#pragma once
#include <chemist/chemist.hpp>
#include <simde/derivative/derivative_pt.hpp>
#include <simde/energy/ao_energy.hpp>

namespace simde {

template<typename PropertyType, typename TensorType>
using NuclearDerivative =
  Derivative<PropertyType, chemist::PointSet<double>, TensorType>;

template<typename TensorType>
using AOEnergyNuclearGradient = NuclearDerivative<AOEnergy, TensorType>;

template<typename TensorType>
using AOEnergyNuclearHessian =
  NuclearDerivative<AOEnergyNuclearGradient<TensorType>, TensorType>;

} // namespace simde

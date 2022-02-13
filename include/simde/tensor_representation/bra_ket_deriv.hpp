#pragma once
#include "simde/types.hpp"
#include "simde/util.hpp"
#include <pluginplay/pluginplay.hpp>

/* Applying BraKet to derivatives
 *
 * BraKet-s define quantities that are relevant in ab-initio calculations. They
 * are defined by the Bra basis set, an operator and the Ket basis set. The
 * BraKet is defined as the integral over the (electron) coordinates of the
 * integrand Bra(r)(Op(Ket(r))).
 *
 * BraKetDeriv-s represent derivatives of the BraKet quantities with respect
 * to some variables. While initially we are mainly interested in gradients
 * (i.e. first order derivatives) it is inevitable that higher order derivatives
 * will follow in future. To denote these higher order derivatives we need
 * the same parameters as for the BraKet quantities (the Bra basis, the
 * operator, and the Ket basis), but now also the variables with respect to
 * which we differentiate. For example to represent the 2nd derivative wrt to
 * the nuclear coordinates we would write
 * BraKetDeriv<Bra,Op,Ket,NucCoord,NucCoord>. The coordinates wrt which we
 * differentiate are gathered in a parameter pack.
 *
 * From here on we need to deal with two scenarios. First we need to deal with
 * the input fields. For this we use recursive templates. At the end of the
 * recursion we declare the same inputs as for BraKet but then add a field for
 * the first differentiation variables. Upon return the invoking template adds
 * its differentiation variables, etc. Ultimately, a collection of input fields
 * has been added that includes all differentiation variables.
 *
 * Second we need to make sure that the outputs are appropriate for the various
 * derivatives. This means we need to generate as the return type a tensor with
 * as many dimensions as there are variables wrt which we differentiate. At
 * compile time the size of each dimension is unknown (e.g. we know that for a
 * gradient the dimensionality of the tensor is 1, but we don't know how many
 * atoms the molecular structure has and so we don't know how many coordinates
 * there are in the gradient).
 */

namespace simde {

template<typename BraType, typename OpType, typename KetType, typename VarDeriv>
DECLARE_TEMPLATED_PROPERTY_TYPE(BraKetDeriv, BraType, OpType, KetType,
                                VarDeriv);

/*
template<typename N, typename BraType, typename OpType, typename VarDeriv,
typename KetType> DECLARE_TEMPLATED_PROPERTY_TYPE(BraKetDeriv, N, BraType,
OpType, VarDeriv, KetType);
*/

/* To add inputs
 */
/*
template<typename BraType, typename OpType, typename VarDeriv, typename KetType>
TEMPLATED_PROPERTY_TYPE_INPUTS(BraKetDeriv, BraType V1, OpType V2, VarDeriv V3,
KetType V4) {
    //constexpr int N = sizeof...(VarDeriv)-1;
    auto rv = BraKetDeriv<BraType,OpType,VarDeriv,KetType>(V1,V2,V3,V4);
    return rv;
}
*/

template<typename BraType, typename OpType, typename KetType, typename VarDeriv>
TEMPLATED_PROPERTY_TYPE_INPUTS(BraKetDeriv, BraType, OpType, KetType,
                               VarDeriv) {
    using op_t   = const OpType&;
    using vard_t = const VarDeriv&;
    // constexpr char field[] = strcat("Derivative",num_to_string<0>);
    constexpr char field[] = "Derivative";

    auto rv = pluginplay::declare_input()
                .add_field<const BraType&>("Bra")
                .template add_field<op_t>("Operator")
                .template add_field<const KetType&>("Ket")
                .template add_field<vard_t>(field);
    return rv;
}

/*
template<int N, typename BraType, typename OpType, typename... VarDerivN,
typename VarDeriv, typename KetType> TEMPLATED_PROPERTY_TYPE_INPUTS(BraKetDeriv,
N, BraType, OpType, VarDerivN..., VarDeriv, KetType) { using op_t = const
OpType&; using vard_t = const VarDeriv&; constexpr char field[] =
strcat("Derivative",num_to_string<N>);

    //auto rv =
BraKetDeriv<N-1,BraType,OpType,VarDerivN,KetType>(N-1,BraType,OpType,VarDerivN,KetType)
    auto rv = BraKetDeriv<N-1,BraType,OpType,VarDerivN,KetType>()
                .template add_field<vard_t>(field);
    return rv;
}
*/

/* To add outputs
 */
template<typename BraType, typename OpType, typename KetType, typename VarDeriv>
TEMPLATED_PROPERTY_TYPE_RESULTS(BraKetDeriv, BraType, OpType, KetType,
                                VarDeriv) {
    // constexpr int N = sizeof...(VarDerivN);
    auto rv =
      pluginplay::declare_result().add_field<simde::type::tensor>("gradient");
    return rv;
}

template<typename BraType>
using ElectronicEnergy_Nuclear =
  BraKetDeriv<BraType, type::els_hamiltonian, BraType, type::molecule>;

template<typename BraType>
using TotalEnergy_Nuclear =
  BraKetDeriv<BraType, type::hamiltonian, BraType, type::molecule>;

} // namespace simde

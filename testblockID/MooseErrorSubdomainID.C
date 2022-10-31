#include "MooseErrorSubdomainID.h"
#include "Function.h"
//libmesh includes supply the p value
//#include "libmesh/quadrature.h"

registerMooseObject(" bunnyApp", MooseErrorSubdomainID);

template<>
InputParameters validParams<MooseErrorSubdomainID>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addClassDescription("test block id");

  return params;
}

MooseErrorSubdomainID::MooseErrorSubdomainID(const InputParameters & parameters) :
    AuxKernel(parameters)
{}
Real
MooseErrorSubdomainID::computeValue()
{
  elem_subdomain_id = _current_elem->subdomain_id();

  mooseWarning("here elem_subdomain_id ", elem_subdomain_id," .");
  return 0;

}

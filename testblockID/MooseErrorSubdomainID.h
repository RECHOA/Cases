#ifndef FASTNEUTRONFLUXAUX_H
#define FASTNEUTRONFLUXAU_H

#include "AuxKernel.h"


//Forward Declarations
class MooseErrorSubdomainID;

template<>
InputParameters validParams<MooseErrorSubdomainID>();
/**
 * Coupled auxiliary value
 */
class MooseErrorSubdomainID : public AuxKernel
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  MooseErrorSubdomainID(const InputParameters & parameters);

protected:
  virtual Real computeValue();
private:

  unsigned int elem_subdomain_id;
  //std::set<SubdomainID> elem_subdomain_id;
};

#endif

#ifndef dealii__cdr_system_matrix_h
#define dealii__cdr_system_matrix_h
#include <deal.II/base/quadrature_lib.h>

#include <deal.II/dofs/dof_handler.h>

#include <deal.II/lac/affine_constraints.h>

#include "parameters.h"

namespace CDR
{
  using namespace dealii;

  template<int dim, typename Matrix>
  void create_system_matrix
  (const DoFHandler<dim>                                    &dof_handler,
   const QGauss<dim>                                        &quad,
   const std::function<std::array<double, dim>(Point<dim>)> &convection_function,
   const CDR::Parameters                                    &parameters,
   const double                                             &time_step,
   Matrix                                                   &system_matrix);

  template<int dim, typename Matrix>
  void create_system_matrix
  (const DoFHandler<dim>                                    &dof_handler,
   const QGauss<dim>                                        &quad,
   const std::function<std::array<double, dim>(Point<dim>)> &convection_function,
   const CDR::Parameters                                    &parameters,
   const double                                             &time_step,
   const AffineConstraints<double>                                   &constraints,
   Matrix                                                   &system_matrix);
}
#endif

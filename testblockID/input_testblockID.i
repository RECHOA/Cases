[Mesh]
  type = FileMesh
  file = testblockid_2.e
[]

[Variables]
  [./temp]
  [../]
[]

[AuxVariables]
  [./for_testid]
  [../]
[]


[AuxKernels]
  [./testid]
    type = MooseErrorSubdomainID
    variable = for_testid
    block = '3 '
  [../]
[]


[Preconditioning]
  [./smp]
    type = SMP
    full = true
  [../]
[]

[Problem]
  type = ReferenceResidualProblem
  kernel_coverage_check = false
[]

[Outputs]
  csv = false
  exodus = false
[]

[Executioner]
  type = Transient
  petsc_options_iname = '-ksp_gmres_restart -pc_type -pc_hypre_type -pc_hypre_boomeramg_max_iter'
  petsc_options_value = '201                hypre    boomeramg      4'
  line_search = 'none'
  solve_type = 'PJFNK'
  nl_rel_tol = 5e-4

  nl_abs_tol = 1e-10
  nl_max_its = 15

  l_tol = 1e-3
  l_max_its = 50

  dtmin = 0.1
  dtmax = 1
  end_time = 1
[]

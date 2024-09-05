/*
drsc.h
******

:author: David Griffin <david.griffin@york.ac.uk>
:coauthors: Rob Davis <rob.davis@york.ac.uk>, Iain Bate <iain.bate@york.ac.uk>
:copyright: 2020, David Griffin / University of York
:license: MIT - A copy of this license should have been provided with this file
:publication: Generating Utilization Vectors for the Systematic Evaluation of Schedulability Tests

Header file to use when calling DRS from C. Modified from the CFFI documentation.
*/

#ifdef __cplusplus
  extern "C" {
#endif

// Magic to make MSVC work

#ifndef CFFI_DLLEXPORT
#  if defined(_MSC_VER)
#    define CFFI_DLLEXPORT  extern __declspec(dllimport)
#  else
#    define CFFI_DLLEXPORT  extern
#  endif
#endif

// set_epsilon: sets the epsilon parameter of DRS
CFFI_DLLEXPORT void drs_set_epsilon(float epsilon);
// set_seed: sets the seed used in DRS
CFFI_DLLEXPORT void drs_set_seed(unsigned int n);
// drs function parameters
// parameter: n - number of entries in the vector
// parameter: sum - sum of values to return
// parameter: lower_bounds - length n array of lower bounds. 0 (null pointer) to run without lower bounds
// parameter: upper_bounds - length n array of upper bounds. 0 (null pointer) to run without upper bounds
// parameter: out - length n array to store output in
// returns: 0 in case of success, non-zero in case of error
CFFI_DLLEXPORT int dirichlet_rescale(
  int n, float sum, float *lower_bounds, float *upper_bounds, float *out);

#ifdef __cplusplus
  }
#endif

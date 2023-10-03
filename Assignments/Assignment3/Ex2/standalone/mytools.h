/*-------------------------------------------------------------------
 * Simple standalone application which requires the GSL random number
 * generator.
 *
 * CSE 380 
 *
 *--------------------------------------------------------------------
 * mytools.h: Header file
 *--------------------------------------------------------------------*/

#include <stdio.h>
#include <gsl/gsl_rng.h>

#ifndef MYTOOLS_H
#define MYTOOLS_H

/* Function prototypes */

int    init_mytool();
void   finalize_mytool();
double get_random_number();

/* Global state variables for GSL */

gsl_rng_type *_gsl_rng_type;
gsl_rng *_gsl_rng;

#endif

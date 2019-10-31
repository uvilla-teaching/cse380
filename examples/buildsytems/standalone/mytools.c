/*-------------------------------------------------------------------
 * Simple standalone application which requires the GSL random number
 * generator.
 *
 * CSE 380 
 *
 *--------------------------------------------------------------------
 * mytools.c: Support functions
 *--------------------------------------------------------------------*/

#include "mytools.h"
#include <time.h>

/* ------------------------------------------------
 * init_mytool(): initialize GSL to query RNG 
 * ------------------------------------------------*/

int init_mytool()
{
  
  _gsl_rng = gsl_rng_alloc(gsl_rng_mt19937); /* init specific rng */
  
  if(_gsl_rng == NULL)
    return 1;
  else
    {
      /* seed  */
      //gsl_rng_set (_gsl_rng, time(0));
      gsl_rng_set (_gsl_rng, 0);

      return 0;
    }

}

/* ------------------------------------------------
 * finalize_mytool(): cleanup GSL
 * ------------------------------------------------*/

void finalize_mytool()
{
  gsl_rng_free (_gsl_rng);
  return;

}

/* -----------------------------------------------------
 * get_random_number(): Use GSL to return random number
 * -----------------------------------------------------*/

double get_random_number()
{
  /* return a double precision floating point number uniformly
     distributed in the range [0,1) */

  return(gsl_rng_uniform (_gsl_rng));
  
}



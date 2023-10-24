/*-------------------------------------------------------------------
 * Simple standalone application which requires the GSL random number
 * generator.
 *
 * CSE 380 
 *
 *--------------------------------------------------------------------
 * main.c: Main program.
 *--------------------------------------------------------------------*/

#include "mytools.h"
#include <assert.h>

int main()
{

  int i;
  const int NUM_ITERS=10;

  /* Step 1: initialize tool */

  assert( init_mytool() == 0);	

  /* Step 2: use tool to get sequence of random numbers */

  for(i=0;i<NUM_ITERS;i++)
    printf("Random number = %f\n",get_random_number());

  /* Step 3: clean up tool */

  finalize_mytool();

  return 0;

}

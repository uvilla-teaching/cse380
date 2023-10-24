#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h> 
#include<assert.h>
#include <sys/types.h>
#include <unistd.h>

double randomDraw(){

  return (double)rand()/RAND_MAX;
}

void usage()
{
  printf("Usage: pi.sh [num_samples]\n");
  printf("   where num_samples is an integer specifying the number\n");
  printf("   of random samples to draw from using Monte Carlo to estimate pi\n\n");
  exit(1);
}

int main(int argc, char *argv[] )
{
  int inside=0;
  int outside=0;
  int numSamples=100;
  double pi_exact = acos(-1);
  double draw1, draw2;
  double radius;

  if(argc < 2)
    usage();

  numSamples=atoi(argv[1]);
  if(numSamples <= 0)
  {
	  printf("numSamples must be > 0\n");
	  exit(1);
  }
  srand(time(0)+getpid());

  for(int i=0;i<numSamples;i++)
    {
      draw1 = randomDraw();
      draw2 = randomDraw();

      if ( (sqrt(draw1*draw1 + draw2*draw2)) > 1.0 )
	outside++;
    }

  inside = numSamples - outside;

  double pi = (double)4.0*inside/numSamples;
  double error = fabs(pi-pi_exact)/pi_exact;
  printf("%i %i %i %f %e\n",numSamples,inside,outside,pi,error);

  return 0;
  
}


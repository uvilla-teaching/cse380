#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  float *array;
  int i;

  array=(float*)calloc(20000,sizeof(float));

  for(i=1;i<=20000;i++)
    array[i] = sqrt(i);
  
  printf("Program complete\n");
  return 0;
}


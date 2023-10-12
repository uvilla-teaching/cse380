#include <stdio.h>
void foo();

int main()
{
  printf("inside main\n");
  foo();
  return 0;
}

void foo()
{
  int i, total=0;
  printf("inside foo\n");
  for(i=0;i<1000;i++)
    total += i;
}


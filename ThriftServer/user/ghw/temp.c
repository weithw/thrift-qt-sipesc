#include <stdlib.h>

struct test{
  int a;
  char b;
};
int main()
{
  struct test my;
  my.a = 5;
  my.b = 'b';
  
  int c = 1+2+3;
  for (c=0;c<100; c++)
    c++;
 
  printf("over\n");
}
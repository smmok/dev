#include <stdio.h>

#define str(x)  # x
#define strs(y) "This is a "#y" going North by another "#y

#define printx(n)   printf("%i\n", x[n])
#define printy(y,n)   printf("%i\n", y##n)

int main(int argc, char argv)
{
  printf(str("Testing # macro.\n")"...\n");

  int x[5];
  for (int i=0; i<5; i++)
    x[i] = i*10;

  int y4 = 400;

  printx(4);
  printy(y,4);

  printf(strs(car)".\n");
  printf(strs(truck)".\n");

  return 0;
}



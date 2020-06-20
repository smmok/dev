#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add(int a, int b){
  return a+b;
}

int subtract(int a, int b){
  return a-b;
}

int multiply(int a, int b){
  return a*b;
}

int getRandomInt(int N){
  time_t t;
  srand((unsigned) time(&t));
  return rand()%(N+1);
}
 
int (*fptr)(int,int);

int main(int argc, char** argv)
{
  printf("%i\n", add(10,5));

  fptr = add;
  printf("%i\n", fptr(10,5));
  
  fptr = subtract;
  printf("%i\n", fptr(10,5));

  
  int select=getRandomInt(2);
  printf("select=%i\n", select);

  switch (select) 
  {
    case 0: fptr = add;
       break;
    case 1: fptr = subtract;
       break;
    default:
       fptr = multiply;
  }
  printf("%i\n", fptr(10,5));  
 
  return 0;
}



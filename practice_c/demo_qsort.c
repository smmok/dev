#include <stdio.h>
#include <stdlib.h>

#define ALEN 10

void printA(int len);
int values[] = {36, 22, 19, 0, 6, 9, 100, 1, 8, 13};

int compare(const void*a, const void*b)
{
  return (*(int*)a - *(int*)b);
}

int main(int argc, char** argv)
{
  printA(ALEN);
  qsort(values, ALEN, sizeof(int), compare);
  printA(ALEN);
  return 0;
}


void printA(int len)
{
  printf("values=[");
  for (int i=0; i<len; i++)
    printf("%i ", values[i]);
  printf("]\n");
}

 

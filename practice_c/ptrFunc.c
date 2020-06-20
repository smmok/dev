#include <stdio.h>

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int quotient(int, int);
int remain(int, int);

int (*mathFunc)(int, int);

int main(int argc, char** argv)
{
	const int a=13;
	const int b=5;
	const int maxNum = 5;

	static int (*pF[])(int,int) = {add, subtract, multiply, quotient, remain};
	for (int i=0; i<maxNum; i++)
	{	
		int result = pF[i](a,b);
		printf("result=%d\n", result);
	}
		
	return 0;
}

int add(int a, int b)
{
	return a+b;
}

int subtract(int a, int b)
{
	return a-b;
}

int multiply(int a, int b)
{
	return a*b;
}

int quotient(int a, int b)
{
	return a/b;
}

int remain(int a, int b)
{
	return a%b;
}




#include <stdio.h>

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int quotient(int, int);
int remain(int, int);

typedef struct {
	char* name;
	int (*mathFunc)(int, int);
} MATHS;

static MATHS maths[] =
	{
		{"adding", add},
		{"subtracting", subtract},
		{"multiplying", multiply},
		{"quotient", quotient},
		{"remainder", remain}
	};

int main(int argc, char** argv)
{
	const int a=13;
	const int b=5;
	const int maxNum = 5;

	for (int i=0; i<maxNum; i++)
	{
		int result = maths[i].mathFunc(a,b);
		printf("result of %s=%d\n", maths[i].name, result);
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




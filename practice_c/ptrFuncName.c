#include <stdio.h>

typedef struct {
	char* name;
	int (*mathFunc)(int, int);
} MATHS;

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int quotient(int, int);
int remain(int, int);

static MATHS maths[] =
	{
		{"adding", add},
		{"subtracting", subtract},
		{"multiplying", multiply},
		{"quotient", quotient},
		{"remainder", remain}
	};

int (*mathFunc)(int,int);
int solve(int (*mathFunc)(int,int), int, int);

int main(int argc, char** argv)
{
	const int a=13;
	const int b=5;
	const int maxNum = 5;

		//int result = maths[i].mathFunc(a,b);
		//printf("result of %s=%d\n", maths[i].name, result);
		int result = solve(add,a,b);
		printf("result=%d\n", result);
		result = solve(subtract,a,b);
		printf("result=%d\n", result);
		result = solve(multiply,a,b);
		printf("result=%d\n", result);
		result = solve(quotient,a,b);
		printf("result=%d\n", result);
		result = solve(remain,a,b);
		printf("result=%d\n", result);
		
	return 0;
}

int solve(int (*mathFunc)(int,int), int p, int q)
{
	return mathFunc(p,q);
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




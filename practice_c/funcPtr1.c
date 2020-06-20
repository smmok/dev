#include <stdio.h>

void fun1() {printf("Fun1\n");};
void fun2() {printf("Fun2\n");};
int leftIsLarger(int left, int right)
{
	if (left>right)
		return 1;
	else
		return 0;
}

void wrapper(void (*fun)())
{
	fun();
}

int wrapper2(int (*func)(int,int),int a, int b)
{
	printf("fun2 left>right: %d\n", func(a,b));
	return 10;
}

typedef int (*wrapperPtr)(int,int);
int (*compare)(int, int);

int main()
{
	wrapper(fun1);
	wrapper(fun2);

	printf("Left is larger for 10,5: %d\n", leftIsLarger(10,5));
	
	compare = leftIsLarger;
	printf("Left is larger for 10,5: %d\n", compare(10,5));

	wrapperPtr wPtr = leftIsLarger;
	printf("main: Left>Right 20,10: %d\n", wPtr(20,10));
	printf("main: Left>Right 20,50: %d\n", wPtr(20,50));

	printf("wrapper2 main: Left>Right 20,50: %d\n", wrapper2(leftIsLarger,30,60));

	return 0;
}


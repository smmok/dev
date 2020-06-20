#include <stdio.h>
#include <stdbool.h>

int sum(const int, const int);
bool leftIsLarger(int, int);

int main(void)
{
	int add_val;
	// int (*p2f)(const int, const int) = &sum;
	int (*p2f)(const int, const int);
	p2f = sum;
	printf("Sum of 5 and 5 is %d\n", sum(5,5));
	printf("Sum of 5 and 5 is %d\n", (*p2f)(5,5));
	printf("Sum of 5 and 5 is %d\n", p2f(5,5));

	bool (*compare)(int, int);
	compare = leftIsLarger;
	printf("Left is larger for  5,10: %d\n", compare(5,10));
	printf("Left is larger for  5,10: %s\n", compare(5,10)?"true":"false");
	printf("Left is larger for 13,10: %s\n", compare(13,10)? "true" : "false");

	return 0;
}

int sum(const int x, const int y)
{
	return x+y;
}

bool leftIsLarger(int left, int right)
{
	if (left>right) 
		return true;
	else
		return false;
}

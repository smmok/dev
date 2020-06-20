// https://www.geeksforgeeks.org/iterative-quick-sort/

#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = (int)*a;
	*a = (int)*b;
	*b = temp;
}

int partition(int A[], int left, int h)
{
	int x = A[h];
	int i = (left-1);

	for (int j=left; j<=h-1; j++)
	{
		if (A[j] <= x) 
		{
			i++;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i+1], &A[h]);
	return (i+1);
}

void quickSortIterative(int A[], int left, int h)
{
	int stack[h-left+1];
	int top = -1;

	stack[++top] = left;
	stack[++top] = h;

	while (top >=0)
	{
		h = stack[top--];
		left = stack[top--];

		int p=partition(A,left,h);

		if (p-1>left)
		{
			stack[++top] = left;
			stack[++top] = p-1;
		}

		if (p+1 < h)
		{
			stack[++top] = p+1;
			stack[++top] = h;
		}
	}
}

void printArray(int A[], int lenA)
{
	printf("\n[ ");
	for (int i=0; i<lenA; i++)
		printf("%d ", A[i]);
	printf("]\n");
}

int main(int argc, char** argv)
{
	int A[] = {3,9,1,-5,0,9,3,2,6,8,7,10};
	int lenA = sizeof(A)/sizeof(A[0]);
	printArray(A,lenA);

	quickSortIterative(A,0,lenA-1);
	printArray(A,lenA);

	return 0;
}

#include <stdio.h>

#define ArrayOffset 1
#define left(x)  2*x+ArrayOffset
#define right(x) 2*x+1+ArrayOffset

void swap(int *a, int *b)
{
	int temp = (int)*a;
	*a = (int)*b;
	*b = temp;
}

void printArray(int A[], int lenA)
{
	printf("\n[ ");
	for (int i=0; i<lenA; i++)
		printf("%d ",A[i]);
	printf("]\n");
}

void heapify(int A[], int heapsize, int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;

	if (l<heapsize && A[l]>A[largest])
		largest = l;
	if (r<heapsize && A[r]>A[largest])
		largest = r;
	if (largest != i)
	{
		swap(&A[i], &A[largest]);
		heapify(A,heapsize,largest);
	}
}

void heapsort(int A[], int lenA)
{
	for (int i=lenA/2-ArrayOffset; i>=0; i--)
		heapify(A,lenA,i);

	for (int heapsize=lenA-ArrayOffset; heapsize>=0; heapsize--)
	{
		swap(&A[0], &A[heapsize]);
		heapify(A,heapsize,0);
	}
}

int main(int argc, char** argv)
{
	int A[] = {6,6,3,1,-3,6,8,2,9,8,20,2,-10};
	int lenA = sizeof(A)/sizeof(A[0]);
	printArray(A,lenA);

	heapsort(A,lenA);
	printArray(A,lenA);

	return 0;
}



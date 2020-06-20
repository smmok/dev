#include <stdio.h>
#include <stdlib.h>

#define left(x) 2*x+1
#define right(x) 2*x+2

void swap(int *a, int *b)
{
	int temp = (int)*a;
	*a = (int)*b;
	*b = temp;
}

void heapify(int A[], int heapsize, int i)
{
	int largest = i;
	int l = left(i);
	int r = right(i);
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

void heapsort(int A[], int size)
{
	for (int i=size/2-1; i>=0; i--)
	 	heapify(A,size,i);
	for (int heapsize=size-1; heapsize>=0; heapsize--)
	{
		swap(&A[0], &A[heapsize]);
		heapify(A,heapsize,0);
	}
}

void printArray(int A[], int lenA)
{
	printf("\n[ ");
	for (int i=0; i<lenA; i++)
		printf("%d ",A[i]);
	printf("]\n");
}

int main(int argc, char** argv)
{
	int A[] = {11,12,5,6,7,13,0,3,3,100,-6,1};
	int lenA = sizeof(A)/sizeof(A[0]);
	printArray(A,lenA);

	heapsort(A,lenA);
	printArray(A,lenA);

	return 0;
}


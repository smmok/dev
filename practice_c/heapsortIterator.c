// https://www.geeksforgeeks.org/iterative-heap-sort/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
	int temp = (int)*a;
	*a = (int)*b;
	*b = temp;
}

void buildMaxHeap(int A[], int n)
{
	// go through all element in heap of size n
	for (int i=1; i<n; i++)
	{
		// if child is larger then parent
		if (A[i] > A[(i-1)/2])
		{
			int j=i;

			// swap child and parent until parent is smaller
			while (A[j]>A[(j-1)/2])
			{
				swap(&A[j], &A[(j-1)/2]);
				j = (j-1)/2;
			}
		}
	}
}

void heapSort(int A[], int n)
{
	buildMaxHeap(A,n);

	for (int i=n-1; i>0; i--)
	{
		// swap value of first with last indexed value
		swap(&A[0], &A[i]);
		// maintaining heap property after each swapping
		int j=0;
		int index;

		do
		{
			index = (2*j+1);
			// if left is smaller than right child
			// point index variable to right child
			if (A[index] < A[index+1] && index<(i-1))
				index++;

			// if parent is smaller than child then
			// swap parent with child having larger value
			if (A[j] < A[index] && index<i)
				swap(&A[j], &A[index]);
			j=index;
		} while (index<i);
	}
}

void heapSortSwee(int A[], int n)
{
	buildMaxHeap(A,n);

	for (int i=n-1; i>0; i--)
	{
		// swap value of first with last indexed value
		swap(&A[0], &A[i]);
		// maintaining heap property after each swapping
		int parent=0;
		int left, right;

		do
		{
			left = (2*parent+1);
			right = left+1;
			// if left is smaller than right child
			// point index variable to right child
			if (A[left]<A[right] && left<(i-1))
				left=right;

			// if parent is smaller than child then
			// swap parent with child having larger value
			if (A[parent] < A[left] && left<i)
				swap(&A[parent], &A[left]);
			parent=left;
		} while (left<i);
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
	int A[] = {6,4,1,0,9,-3,9,8,3,7,30};
	int lenA = sizeof(A)/sizeof(A[0]);
	int lenB = lenA;
	int *B = (int*)malloc(sizeof(int)*lenB);
	memcpy(B,A,sizeof(int)*lenA);
	printArray(A,lenA);
	printArray(B,lenB);

	heapSort(A,lenA);
	printArray(A,lenA);
	printArray(B,lenB);

	heapSortSwee(B,lenB);
	printArray(A,lenA);
	printArray(B,lenB);

	return 0;
}


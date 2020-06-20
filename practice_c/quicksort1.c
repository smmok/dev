#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void quicksort(int*, int, int);
int  partition(int*, int, int);
void printArray(int*, int);
void swap(int*, int*);

void mergesort(int*, int, int);
void merge(int*, int, int, int);

int main(int argc, char** argv)
{
	int A[] = {4,0,9,1,2,3,8,7,5,6};
	int lenA = sizeof(A)/sizeof(A[0]);
	printArray(A,lenA);

	quicksort(A,0,lenA-1);
	printArray(A,lenA);

	int B[] = {4,0,9,3,2,1,7,6,5,8};
	int lenB = sizeof(B)/sizeof(B[0]);
	printArray(B,lenB);

	mergesort(B,0,lenB-1);
	printArray(B,lenB);

	return 0;
}

void mergesort(int A[], int left, int right)
{
	if (left < right)
	{
		int mid = left + floor((right-left)/2);
		mergesort(A,left,mid);
		mergesort(A,mid+1,right);
		merge(A,left,mid,right);
	}
}

void merge(int A[], int left, int mid, int right)
{
	int i,j,k;
	int n1 = mid-left+1;
	int n2 = right-mid;
	int L[n1], R[n2];

	for (i=0; i<n1; i++)
		L[i]=A[left+i];
	for (j=0; j<n2; j++)
		R[j]=A[mid+1 +j];

	i=0; j=0; k=left;

	while (i<n1 && j<n2)
	{
		if (L[i]<R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
		k++;
	}

	while (i<n1)
	{
		A[k]=L[i];
		i++;
		k++;
	}

	while (j<n2)
	{
		A[k]=R[j];
		j++;
		k++;
	}
}

void quicksort(int A[], int p, int r)
{
	if (p<r)
	{
		int q = partition(A,p,r);
		quicksort(A,p,q);
		quicksort(A,q+1,r);
	}
}

int partition(int A[], int p, int r)
{
	int i,j,x;
	i = p-1;
	j = r+1;
	x = A[p];

	while (true)
	{
		do { j--;
		} while (A[j]>x && j>0);

		do { i++;
		} while (A[i]<x && i<r);

		if (i<j)
			swap(&A[i], &A[j]);
		else
			return j;
	}
}

void swap(int* a, int* b)
{
	int temp = (int)*a;
	*a = (int)*b;
	*b = temp;
}

void printArray(int* A, int lenA)
{
	printf("\n[ ");
	for (int i=0; i<lenA; i++)
		printf("%d ", A[i]);
	printf("]\n");
}



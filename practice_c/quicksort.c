#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void printArray(int*, int);
void quicksort(int*, int, int);
int partition(int*, int, int);
void mergesort(int*, int, int);
void merge(int*, int, int, int);

int main(int argc, char** argv)
{
	int A[] = {4,9,1,0,6,5,2,7,8,3};
	int lenA = sizeof(A)/sizeof(A[0]);
	printArray(A,lenA);

	quicksort(A,0,lenA-1);
	printArray(A,lenA);

	int B[] = {4,9,1,0,6,5,7,2,3,8};
	int lenB = sizeof(B)/sizeof(B[0]);
	printArray(B,lenB);

	mergesort(B,0,lenB-1);
	printArray(B,lenB);

	return 0;
}

void printArray(int* A, int lenA)
{
	int i;
	printf("\n[ ");
	for (i=0; i<lenA; i++)
		printf("%d ",A[i]);
	printf("]\n");
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
	int i,j,pivot;
	i=p-1;
	j=r+1;
	pivot=A[p];

	while (true)
	{
		do {
			j--;
		} while (A[j]>pivot && j>0);

		do {
			i++;
		} while (A[i]<pivot && i<r);

		if (i<j)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		else
			return j;
	}
}

void mergesort(int A[], int left, int right)
{
	if (left<right)
	{
		int mid = left + (int)floor((right-left)/2);
		mergesort(A,left,mid);
		mergesort(A,mid+1,right);
		merge(A,left,mid,right);
	}
}

void merge(int A[], int left, int mid, int right)
{
	int i,j,k;
	int n1 = mid-left+1;
	int n2 = right - mid;

	int L[n1], R[n2];
	for (i=0; i<n1; i++)
		L[i]=A[left+i];
	for (j=0; j<n2; j++)
		R[j]=A[mid+1+j];

	i=0;
	j=0;
	k=left;

	while (i<n1 && j<n2)
	{
		if (L[i] <= R[j])
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


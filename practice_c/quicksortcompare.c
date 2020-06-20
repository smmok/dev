#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef int (*Compare)(int,int);

void quicksort(int*, int, int, Compare);
int  partition(int*, int, int, Compare);
void printArray(int*, int);
void swap(int*, int*);

void mergesort(int*, int, int, Compare);
void merge(int*, int, int, int, Compare);

int leftIsSmaller(int left, int right);
int leftIsLarger(int left, int right);

int main(int argc, char** argv)
{
	Compare cmp;
	int A[] = {4,0,9,1,2,3,8,7,5,6};
	int lenA = sizeof(A)/sizeof(A[0]);
	printArray(A,lenA);

	printf("\n===== Quicksort =====\n");
	cmp = leftIsSmaller;
	quicksort(A,0,lenA-1,cmp);
	printArray(A,lenA);

	cmp = leftIsLarger;
	quicksort(A,0,lenA-1,cmp);
	printArray(A,lenA);

	printf("\n===== Mergesort =====\n");

	int B[] = {4,0,9,3,2,1,7,6,5,8};
	int lenB = sizeof(B)/sizeof(B[0]);
	printArray(B,lenB);

	cmp = leftIsSmaller;
	mergesort(B,0,lenB-1,cmp);
	printArray(B,lenB);

	cmp = leftIsLarger;
	mergesort(B,0,lenB-1,cmp);
	printArray(B,lenB);

	return 0;
}


int leftIsSmaller(int left, int right)
{
	if (left < right)
		return true;
	else
		return false;
}

int leftIsLarger(int left, int right)
{
	if (left>right)
		return true;
	else
		return false;
}

void mergesort(int A[], int left, int right, Compare compare)
{
	if (left < right)
	{
		int mid = left + floor((right-left)/2);
		mergesort(A,left,mid,compare);
		mergesort(A,mid+1,right,compare);
		merge(A,left,mid,right,compare);
	}
}

void merge(int A[], int left, int mid, int right, Compare compare)
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
		//if (L[i]>R[j])
		if (compare(L[i],R[j]))
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

void quicksort(int A[], int p, int r, Compare compare)
{
	if (p<r)
	{
		int q = partition(A,p,r,compare);
		quicksort(A,p,q,compare);
		quicksort(A,q+1,r,compare);
	}
}

int partition(int A[], int p, int r, Compare compare)
{
	int i,j,x;
	i = p-1;
	j = r+1;
	x = A[p];

	while (true)
	{
		do { j--;
		//} while (A[j]<x && j>0);
		} while (compare(x,A[j]) && j>0);

		do { i++;
		//} while (A[i]>x && i<r);
		} while (compare(A[i],x) && i<r);

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



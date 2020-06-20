#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p, const void *q)
{
	int l = *(const int*)p;
	int r = *(const int*)q;
	if (l==r) 
		return 0;
	else
		if (l<r)
			return -1;
		else
			return 1;
}

void printArr(int arr[], int n)
{
	printf("\n[ ");
	for (int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("]\n");
}

int main(int argc, char** argv)
{
	int arr[] = {1,6,5,2,3,9,4,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Original array is:");
	printArr(arr,size);
	qsort((void*)arr, size, sizeof(arr[0]), comparator);

	printf("qsorted array is:");
	printArr(arr, size);

	return 0;
}



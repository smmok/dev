#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <time.h>

struct node {
	int data;
	struct node* next;
};

void push(struct node**, int);
void printlist(struct node*, int);
int search(struct node* head, int data);
static int printCount=0;

int main(int argc, char** argv)
{
	int count=0;
	int duplicate=0;
	int duplicateCount=0;
	int bucket=0;
	int r=0;
	const int numBuckets = 6;
	int Samples = 1000000;
	int largestNumber = 2000000;

	struct node* H[numBuckets];
	for (int i=0; i<numBuckets; i++)
		H[i] = NULL;

	srand((unsigned int) time (NULL));

	while (count<Samples)
	{
		r = rand() / (RAND_MAX/largestNumber+1);
		bucket = r%numBuckets;
		duplicate = search(H[bucket],r);
		if (duplicate)
		{
			duplicateCount++;
		}
		else
		{
 			//printf("[%d]",r);
			push(&H[bucket], r);
			count++;
		}
	}

	for (int i=0; i<numBuckets; i++)
		printlist(H[i],i);

	printf("Numbers generated=%d\n", printCount);
	printf("Duplicates found =%d\n", duplicateCount);

	return 0;
};

int search(struct node* head, int data)
{
	if (head==NULL)
	{
		return 0;
	}
	else
	{
		while (head!=NULL)
		{
			if (head->data==data)
				return 1;
			else
				head = head->next;
		}
		return 0;
	}
}

void push(struct node** headRef, int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	struct node* head = *headRef;

	if (newNode==NULL)
	{
		printf("newNode malloc failed.\n");
		exit(1);
	}

	newNode->data = data;

	if (head==NULL)
	{
		newNode->next = *headRef;
		*headRef = newNode;
		return;
	}

	if (head->data > data)
	{
		newNode->next = *headRef;
		*headRef = newNode;
		return;
	}

	if (head->data < data)
	{
		while(head!=NULL)
  		{
  			if (head->next==NULL)
  			{
  				newNode->next = head->next;
  				head->next = newNode;
				return;
  			}

  			if (head->next->data > data)
  			{
  				newNode->next = head->next;
  				head->next = newNode;
				return;
  			}
  			head = head->next;
  		}
 	}
}

void printlist(struct node* head, int index)
{
	struct node* dummy = head;

	printf("\n[%d]=[", index);
	while (dummy!=NULL)
	{
		printf("%d ", dummy->data);
		dummy = dummy->next;
		printCount++;
	}
	printf("]\n");
}







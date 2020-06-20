// Generate unique random numbers using hashing

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

struct node {
	int data;
	struct node *next;
};

struct node *bucks[33];
void addtolist(int, int);
void printlist(int,int);
int search_list(int,int);

int main(int argc, char** argv)
{
	int num, sflag, count=0, duplicateCount=0;
	char ch;
	srand((unsigned) time(NULL));

	// Initialize pointers
	for (int i=0; i<33; i++)
		bucks[i]=NULL;

	while (count<1000)
	{
		printf("[%d:",count);
		num = rand() / (RAND_MAX/32767+1);
		sflag = search_list(num/1000, num);
		if (sflag)
		{
			printf("%d in List]\n", num);
			duplicateCount++;
		}
		else
		{
			printf("%d]", num);
			addtolist(num/1000, num);
			count++;
		}
	}

	printf("\n");
	printlist(count,duplicateCount);

	return 0;
}

void addtolist(int index, int data)
{
	struct node *q, *r, *temp;
	temp = q = bucks[index];
	r = (struct node*)malloc(sizeof(struct node));
	if (r==NULL)
	{	printf("Problem allocating memory for r!\n");
		exit(1);
	}
	else
	{
		r->data = data;
		r->next = NULL;
	}

	if (q==NULL || q->data > data)
	{
		q = r;
		q->next = temp;
		bucks[index] = q;
	}
	else
	{
		while (temp != NULL)
		{
			if ((temp->data<data) && (temp->next==NULL))
			{
				r->next = temp->next;
				temp->next = r;
				return;
			}
			if ((temp->data<data) && (temp->next->data > data))
			{
				r->next = temp->next;
				temp->next = r;
				return;
			}
			temp=temp->next;
		}
	}
}

int search_list(int index, int data)
{
	struct node *p;
	p = bucks[index];
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		while (p!=NULL)
		{
			if (p->data==data)
				return 1;
			else
				p=p->next;
		}
		return 0;
	}
}

void printlist(int count, int duplicateCount)
{
	struct node *p;
	int i;
	int numRnd = 0;
	printf("\nList(%d),duplicateCount=%d:\n",count,duplicateCount);
	for (i=0; i<33; i++)
	{
		p = bucks[i];
		printf("%d:[ ",i);
		while (p!=NULL)
		{
			printf("%d ", p->data);
			p=p->next;
			numRnd++;
		}
		printf("]\n");
	}
	printf("\n");
	printf("num Rnd generated=%d\n", numRnd);
}

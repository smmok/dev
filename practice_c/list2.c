#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Record Record;
struct Record {
	int data;
	Record* next;
};

void AddRecord(Record** headRef, int data)
{
	Record* newRecord = malloc(sizeof(Record));

	newRecord->data = data;
	newRecord->next = *headRef;
	*headRef = newRecord;
}

void printList(Record* head)
{
	Record* current = head;
	printf("[ ");
	while (current!=NULL)
	{
		printf("%d ", current->data);
		current=current->next;
	}
	printf("]\n");
}

int main(int argc, char** argv)
{
	Record* head = NULL;
	printList(head);

	AddRecord(&head, 100);
	AddRecord(&head, 200);
	AddRecord(&head, 300);
	printList(head);

	return 0;
}



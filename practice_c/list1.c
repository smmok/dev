#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node Node;
struct Node {
	int data;
	Node* next;
};

void Push(Node**, int);
void printList(Node*);
int length(Node*);
void moveNode(Node** sourceRef, Node** destRef);


int main(int argc, char** argv)
{
	Node* head = NULL;
	Push(&head, 10);
	Push(&head, 20);
	Push(&head, 30);

	printList(head);
	printf("List length=%d\n", length(head));

	Node* head2 = NULL;
	Push(&head2, 100);
	Push(&head2, 200);
	Push(&head2, 300);
	printList(head2);

	moveNode(&head, &head2);
	printList(head);
	printList(head2);
	printf("-----\n");

	moveNode(&head, &head2);
	printList(head);
	printList(head2);
	printf("-----\n");

	moveNode(&head, &head2);
	printList(head);
	printList(head2);

	return 0;
}

void moveNode(Node** sourceRef, Node** destRef)
{
	Node* newNode = *sourceRef;
	assert(newNode != NULL);

	*sourceRef = newNode->next;
	newNode->next = *destRef;
	(*destRef) = newNode;
}

int length(Node* head)
{
	Node* current = head;
	int count=0;

	while (current!=NULL)
	{
		count++;
		current=current->next;
	}
	return count;
}

void Push(Node** headRef, int data)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

void printList(Node* head)
{
	Node* current = head;
	printf("[ ");
	while (current!=NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("]\n");
}



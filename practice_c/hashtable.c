#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct Node Node;
struct Node {
	int key;
	char* data;
	Node* next;
};

Node** initHashTable(int);
void insert(Node**, int, int, char*);
void displayList(Node**, int);
int hashCode(int,int);
char* get(Node**,int,int);

int main(int argc, char** argv)
{
	int hashSize=5;
	static int numElements = 10;

	Node** hashArray = initHashTable(hashSize);

	char* Data[] = {"Zero", "One", "Two", "Three", "Four", \
					"Five", "Six", "Seven", "Eight", "Nine"};
	for (int i=0; i<numElements; i++)
		insert(hashArray, hashSize, i, Data[i]);
	
	displayList(hashArray, hashSize);

//	for (int i=0; i<numElements; i++)
//		printf("hash of %d=%s\n", i, get(hashArray, hashSize,i));

	return 0;
}


Node** initHashTable(int hashSize)
{
	Node** hashArray = malloc(sizeof(Node*)*hashSize);
	for (int i=0; i<hashSize; i++)
		hashArray[i] = NULL;
	return hashArray;
}

int hashCode(int key, int hashSize)
{
	return key%hashSize;
}

void insert(Node** hashArray, int hashSize, int key, char* data)
{
	int hashIndex = hashCode(key,hashSize);
	Node* newNode = malloc(sizeof(Node));

	newNode->key = key;
	newNode->data = strdup(data);
	newNode->next = hashArray[hashIndex];
	hashArray[hashIndex] = newNode;
}

char* get(Node** hashArray, int hashSize, int key)
{
	int hashIndex = hashCode(key,hashSize);
	for (int i=0; i<hashSize; i++)
	{
		Node* current = hashArray[i];
		while(current!=NULL)
		{
			if (current->key == key)
				return current->data;
			current-current->next;
		}
	}
}

void displayList(Node** hashArray, int hashSize)
{
	Node* current;
	int i;
	for (i=0; i<hashSize; i++)
	{
		current = hashArray[i];
		while (current!=NULL)
		{
			printf("[%d]=%s ", i, current->data);
			current = current->next;
		}
		printf("\n");
	}
}


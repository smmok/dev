#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node Node;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data);
Node* insert(Node* node, int data);
void displayTree(Node* tree);
int minValue(Node* tree);

int main(int argc, char** argv)
{
	Node* tree = NULL;
	tree = insert(tree, 5);
	tree = insert(tree, 8);
	tree = insert(tree, 3);
	tree = insert(tree, 2);
	tree = insert(tree, 9);
	tree = insert(tree, 7);
	displayTree(tree);
	printf("\n");

	printf("Min value = %d\n", minValue(tree));

	return 0;
}

int minValue(Node* tree)
{
	Node* current = tree;

	while (current->left != NULL)
		current = current->left;
	
	return (int)(current->data);
}

Node* newNode(int data)
{
	Node* newNode = malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

Node* insert(Node* node, int data)
{
	if (node==NULL)
		return newNode(data);
	
	if (data < node->data)
		node->left = insert(node->left,data);
	else
		node->right = insert(node->right,data);
	
	return node;
}

void displayTree(Node* tree)
{
	Node* current = tree;

	if (current != NULL)
	{
		displayTree(current->left);
		printf("%d ", current->data);
		displayTree(current->right);
	}
}



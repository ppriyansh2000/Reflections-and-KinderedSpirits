// Sean Szumlanski
// COP 3502, Fall 2020

// =============================
// Kindred Spirits: testcase03.c
// =============================
// Test whether two distinct nodes with the same value are considered
// reflections of one another.


#include <stdio.h>
#include <stdlib.h>
#include "KindredSpirits.h"

// A pretty standard create_node() function. Creates a new binary tree node,
// initializes its members, and returns a pointer to the new node.
node *create_node(int data)
{
	node *n = malloc(sizeof(node));

	n->data = data;
	n->left = n->right = NULL;

	return n;
}

int main(void)
{
	node *node1, *node2;

	// Let's establish some trees that each have just a single node.
	node1 = create_node(15);
	node2 = create_node(15);

	if (isReflection(node1, node2))
		printf("Success!\n");
	else
		printf("fail whale :(\n");

	// Clean up after yourself.
	free(node1);
	free(node2);

	return 0;
}

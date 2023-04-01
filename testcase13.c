// Sean Szumlanski
// COP 3502, Fall 2020

// =============================
// Kindred Spirits: testcase13.c
// =============================
// Another test of the kindredSpirits() function.


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

	// Let's establish some trees with just a single element.
	node1 = create_node(15);
	node2 = create_node(15);

	printf("%s\n", kindredSpirits(node1, node2) ? "Success!" : "fail whale :(");

	// Clean up after yourself.
	free(node1);
	free(node2);

	return 0;
}

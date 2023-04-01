// Sean Szumlanski
// COP 3502, Fall 2020

// =============================
// Kindred Spirits: testcase04.c
// =============================
// Test whether a tree with a single node is considered a reflection of itself.


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
	node *root;

	// Let's establish a tree that each have just a single node.
	root = create_node(15);

	// Compare the single-node tree with itself.
	if (isReflection(root, root))
		printf("Success!\n");
	else
		printf("fail whale :(\n");

	// Clean up after yourself.
	free(root);

	return 0;
}

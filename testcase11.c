// Sean Szumlanski
// COP 3502, Fall 2020

// =============================
// Kindred Spirits: testcase11.c
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

// Free all the nodes in a binary tree.
node *forest_fire(node *root)
{
	if (root == NULL)
		return NULL;

	forest_fire(root->left);
	forest_fire(root->right);
	free(root);

	return NULL;
}

int main(void)
{
	node *root;

	// These is one of the trees from Figure 9 in the assignment PDF. It is not a
	// kindred spirit of itself.
	root = create_node(23);
	root->left = create_node(12);
	root->left->left = create_node(5);
	root->left->right = create_node(18);
	root->right = create_node(71);
	root->right->right = create_node(56);

	printf("%s\n", !kindredSpirits(root, root) ? "Success!" : "fail whale :(");

	// Clean up after yourself.
	forest_fire(root);

	return 0;
}

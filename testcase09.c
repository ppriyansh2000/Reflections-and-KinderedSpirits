// Sean Szumlanski
// COP 3502, Fall 2020

// =============================
// Kindred Spirits: testcase09.c
// =============================
// A basic test of the kindredSpirits() function.


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
	node *root1, *root2;

	// These are the trees from Figure 9 in the assignment PDF, used for testing
	// the kindredSpirits function.
	root1 = create_node(23);
	root1->left = create_node(12);
	root1->left->left = create_node(5);
	root1->left->right = create_node(18);
	root1->right = create_node(71);
	root1->right->right = create_node(56);

	root2 = create_node(56);
	root2->left = create_node(23);
	root2->right = create_node(71);
	root2->right->left = create_node(5);
	root2->right->left->right = create_node(12);
	root2->right->right = create_node(18);

	printf("%s\n", kindredSpirits(root1, root2) ? "Success!" : "fail whale :(");

	// Clean up after yourself.
	forest_fire(root1);
	forest_fire(root2);

	return 0;
}

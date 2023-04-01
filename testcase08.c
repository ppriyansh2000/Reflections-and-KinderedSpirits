// Sean Szumlanski
// COP 3502, Fall 2020

// =============================
// Kindred Spirits: testcase08.c
// =============================
// Slightly more complex test of makeReflection() and isReflection().


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

	// Let's create a slightly more complex tree than in previous test cases.
	// This is the tree from Figure 4 in the assignment PDF. This approach is
	// super hacky and terrible, and you should never do something like this!
	root1 = create_node(2);
	root1->left = create_node(14);
	root1->right = create_node(14);
	root1->left->left = create_node(62);
	root1->left->right = create_node(62);
	root1->right->left = create_node(62);
	root1->right->right = create_node(62);
	root1->left->left->left = create_node(34);
	root1->left->left->right = create_node(34);
	root1->left->right->left = create_node(34);
	root1->left->right->right = create_node(34);
	root1->right->left->left = create_node(34);
	root1->right->left->right = create_node(34);
	root1->right->right->left = create_node(34);
	root1->right->right->right = create_node(34);

	// Reflect the tree.
	root2 = makeReflection(root1);

	// Ensure these are reflections.
	if (isReflection(root1, root2))
		printf("Success!\n");
	else
		printf("fail whale :(\n");

	// Clean up after yourself.
	forest_fire(root1);
	forest_fire(root2);

	return 0;
}

// Sean Szumlanski
// COP 3502, Fall 2020

// =============================
// Kindred Spirits: testcase07.c
// =============================
// Test whether the empty tree is considered a reflection of a non-empty tree.


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

	// Let's build a tree! This is a super hacky and terrible way of making the
	// left binary tree from Figure 1 in the assignment PDF. Please don't ever
	// do anything this terrible, hacky, and inelegant in your own code.
	root1 = create_node(10);
	root1->left = create_node(20);
	root1->right = create_node(30);
	root1->right->left = create_node(40);
	root1->right->right = create_node(1);

	// Reflect the tree.
	root2 = makeReflection(root1);

	// Empty tree vs. non-empty tree. These should not be reflections of one
	// another.
	if (!isReflection(NULL, root2))
		printf("Success!\n");
	else
		printf("fail whale :(\n");

	// Clean up after yourself.
	forest_fire(root1);
	forest_fire(root2);

	return 0;
}

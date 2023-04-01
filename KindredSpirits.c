// Priyansh Patel
// COP 3502c, Fall 2020
// NID - pr348838
// Assignment 4 - KindredSpirits and Reflections

#include <stdio.h>
#include <stdlib.h>
#include "KindredSpirits.h"

// creates a new node for the tree
node *createNode(int data)
{
  node *n = calloc(1, sizeof(node));

  n->data = data;
  n->left = NULL;
  n->right = NULL;

  return n;
}


// code used from more-recursive-tree-functions.c
int countNodes(node *root)
{
  // base case: empty tree
  if (root == NULL)
  {
    return 0;
  }

  return 1 + countNodes(root->left) + countNodes(root->right);
}


node *makeReflection(node *root)
{
  node *n = NULL;

  // checks for empty tree
  if (root == NULL)
  {
    return NULL;
  }

  // create a new node recursively
  n = createNode(root->data);

  // mirrors the tree
  n->right = makeReflection(root->left);
  n->left = makeReflection(root->right);

  return n;
}


int isReflection(node *a, node *b)
{
  // empty trees are reflections
  if (a == NULL && b == NULL)
  {
    return 1;
  }

  // checks if one is empty and other is not
  // if true then they are not a reflection
  if ((a == NULL && b != NULL) || (a != NULL && b == NULL))
  {
    return 0;
  }

  // checks the value in node
  if (a->data != b->data)
  {
    return 0;
  }

  // recursive conditions: checks both left and right in each node
  if (isReflection(a->left, b->right) && isReflection(a->right, b->left))
  {
    return 1;
  }

  return 0;
}


// code from bst.c (modified)
void preorder_recursive(node *root, int *counter, int *array)
{
  if (root == NULL)
  {
    return;
  }

  // variable counter is used as an pass by reference
  array[(*counter)++] = root->data;
  preorder_recursive(root->left, counter, array);
  preorder_recursive(root->right, counter, array);
}


// values in the array are in preorder
int *preorder(node *root, int count)
{
  int *array = malloc((sizeof(int) * count));
  int counter = 0;

  preorder_recursive(root, &counter, array);
  return array;
}


// code from bst.c (modified)
void postorder_recursive(node *root, int *counter, int *array)
{
  if (root == NULL)
  {
    return;
  }

  postorder_recursive(root->left, counter, array);
  postorder_recursive(root->right, counter, array);
  array[(*counter)++] = root->data;
}


// values in the array are in postorder
int *postorder(node *root, int count)
{
  int *array = malloc((sizeof(int) * count));
  int counter = 0;

  postorder_recursive(root, &counter, array);
  return array;
}


// helper function for kindredSpirits()
// compares if two arrays have the same elements
int compare(int *array1, int *array2, int count)
{
  int i, check = 0;

  for (i = 0; i < count; i++)
  {
    if (array1[i] == array2[i])
    {
      check++;
    }
  }

  if (check == count)
  {
    return 1;
  }

  return 0;
}


int kindredSpirits(node *a, node *b)
{
  int count_a, count_b, i;
  int *array_1, *array_2;
  int check1, check2;

  // empty trees are kindredSpirits
  if (a == NULL && b == NULL)
  {
    return 1;
  }

  count_a = countNodes(a);
  count_b = countNodes(b);

  // check if both trees have equal amounts of nodes
  if (count_a != count_b)
  {
    return 0;
  }

  array_1 = preorder(a, count_a);
  array_2 = postorder(b, count_b);

  check1 = compare(array_1, array_2, count_a);

  array_1 = postorder(a, count_a);
  array_2 = preorder(b, count_b);

  check2 = compare(array_1, array_2, count_b);

  // if one of them is true then both trees are kindredSpirits
  if (check1 == 1 || check2 == 1)
  {
    return 1;
  }

  return 0;
}


double difficultyRating(void)
{
  return 3.2;
}


double hoursSpent(void)
{
  return 24.0;
}

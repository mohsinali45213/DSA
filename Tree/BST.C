#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int value)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL)
  {
    printf("Memory Allocation Failed...\n");
    exit(1);
  }
  newnode->data = value;
  newnode->right = NULL;
  newnode->left = NULL;
  return newnode;
}

int isBST(struct node *root)
{
  static struct node *prev = NULL;
  if (root != NULL)
  {
    if (!isBST(root->left))
    {
      return 0;
    }
    if (prev != NULL && root->data <= prev->data)
    {
      return 0;
    }
    prev = root;
    return isBST(root->right);
  }
  else
  {
    return 1;
  }
}

void BST(struct node *root, int key)
{
  if (root == NULL)
  {
    printf("Key Not Found");
    return;
  }
  if (root->data == key)
  {
    printf("Found : %d", root->data);
    return;
  }
  else if (root->data > key)
  {
    BST(root->left, key);
  }
  else
  {
    BST(root->right, key);
  }
}

int main()
{
  struct node *root = createNode(5);
  struct node *n1 = createNode(3);
  struct node *n2 = createNode(7);
  struct node *n3 = createNode(2);
  struct node *n4 = createNode(4);
  struct node *n5 = createNode(6);
  struct node *n6 = createNode(8);

  root->left = n1;
  root->right = n2;
  n1->left = n3;
  n1->right = n4;
  n2->left = n5;
  n2->right = n6;

  if (isBST(root))
  {
    printf("It is a valid BST...\n");
    BST(root, 3);
  }
  else
  {
    printf("It is not valid BST...");
  }
}

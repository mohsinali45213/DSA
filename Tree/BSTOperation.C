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

void insertion(struct node *root, int key)
{
  struct node *prev = NULL;
  while (root != NULL)
  {
    prev = root;
    if (root->data == key)
    {
      printf("Element already present in the tree...\n");
      return;
    }
    else if (root->data > key)
    {
      root = root->left;
    }
    else
    {
      root = root->right;
    }
  }
  struct node *newnode = createNode(key);
  if (prev->data > key)
  {
    prev->left = newnode;
  }
  else
  {
    prev->right = newnode;
  }
}

void inorder(struct node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
  }
}

int main()
{
  struct node *root = createNode(10);
  struct node *n1 = createNode(5);
  struct node *n2 = createNode(15);
  struct node *n3 = createNode(2);
  struct node *n4 = createNode(7);
  struct node *n5 = createNode(12);
  struct node *n6 = createNode(17);

  root->left = n1;
  root->right = n2;
  n1->left = n3;
  n1->right = n4;
  n2->left = n5;
  n2->right = n6;

  if (isBST(root))
  {
    printf("It is a valid BST...\n");
    insertion(root,9);
    inorder(root);
    printf("NULL");
  }
  else
  {
    printf("It is not valid BST...");
  }
}

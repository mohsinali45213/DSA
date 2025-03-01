#include <stdio.h>
#include <conio.h>
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

void preorder(struct node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node *root)
{
  if (root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}
void inorder(struct node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main()
{
  struct node *root = createNode(1);
  struct node *n1 = createNode(2);
  struct node *n2 = createNode(3);
  struct node *n3 = createNode(4);
  struct node *n4 = createNode(5);
  struct node *n5 = createNode(6);
  struct node *n6 = createNode(7);

  root->left = n1;
  root->right = n2;
  n1->left = n3;
  n1->right = n4;
  n2->left = n5;
  n2->right = n6;

  preorder(root);
  printf("\n");
  inorder(root);
  printf("\n");
  postorder(root);
}
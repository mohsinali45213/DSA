#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *llink;
  struct node *rlink;
};

typedef struct node *Node;
Node create(Node, int);
Node getnode(int);
void inorder(Node);
void main()
{
  int item, op;
  Node root = NULL;

  do
  {
    printf("\n1. Insert\n2. Inorder\n3. Exit\nEnter your choice: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      printf("Enter the item to be inserted: ");
      scanf("%d", &item);
      root = create(root, item);
      break;
    case 2:
      printf("Inorder Traversal: ");
      inorder(root);
      break;
    case 3:
      exit(0);
    default:
      printf("Invalid choice! Please try again.\n");
    }
  } while (op != 3);
}

Node getnode(int data)
{
  Node x = (Node)malloc(sizeof(struct node));
  x->data = data;
  x->llink = NULL;
  x->rlink = NULL;
  return x;
}

Node create(Node root, int data)
{
  Node temp, cur, prev;
  temp = getnode(data);
  if (root == NULL)
  {
    return temp;
  }
  cur = root;
  while (cur != NULL)
  {
    prev = cur;
    if (data < cur->data)
    {
      cur = cur->llink;
    }
    else
    {
      cur = cur->rlink;
    }
  }
  if (prev->data > data)
  {
    prev->llink = temp;
  }
  else
  {
    prev->rlink = temp;
  }
  return root;
}

void inorder(Node root)
{
  if (root != NULL)
  {
    inorder(root->llink);
    printf("%d ", root->data);
    inorder(root->rlink);
  }
}
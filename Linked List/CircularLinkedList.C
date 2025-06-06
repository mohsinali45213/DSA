#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
void insertFirst(int);
void insertLast(int);
void insertMiddle(int, int);
void deleteFirst();
void deleteLast();
void deleteMiddle(int);
void display();
struct Node *createNode(int);
struct Node *head = NULL;

int main()
{
  int op, data, index;
  while (1)
  {
    printf("\n1 : InsertFirst\n");
    printf("2 : InsertLast\n");
    printf("3 : InsertMiddle\n");
    printf("4 : DeleteFirst\n");
    printf("5 : DeleteLast\n");
    printf("6 : DeleteMiddle\n");
    printf("7 : Exit\n");
    printf("Enter Option\n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      printf("\nEnter element to be insert\n");
      scanf("%d", &data);
      insertFirst(data);
      display();
      break;
    case 2:
      printf("\nEnter element to be insert\n");
      scanf("%d", &data);
      insertLast(data);
      display();
      break;
    case 3:
      printf("\nEnter element to be insert\n");
      scanf("%d", &data);
      printf("\nEnter index to be insert\n");
      scanf("%d", &index);
      insertMiddle(data, index);
      display();
      break;
    case 4:
      deleteFirst();
      display();
      break;
    case 5:
      deleteLast();
      display();
      break;
    case 6:
      printf("\nEnter index to be deleted\n");
      scanf("%d", &index);
      deleteMiddle(index);
      display();
      break;
    case 7:
      exit(0);
    default:
      break;
    }
  }
}

struct Node *createNode(int value)
{
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  if (newnode == NULL)
  {
    printf("Memory Allocation Failed...\n");
    exit(1);
  }
  newnode->data = value;
  newnode->next = NULL;
  return newnode;
}

void insertFirst(int value)
{
  struct Node *newnode = createNode(value);
  if (head == NULL)
  {
    newnode->next = newnode;
    head = newnode;
  }
  else
  {
    struct Node *temp = head;
    while (temp->next != head)
    {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
  }
}

void insertLast(int value)
{
  struct Node *newnode = createNode(value);
  if (head == NULL)
  {
    newnode->next = newnode;
    head = newnode;
  }
  else
  {
    struct Node *temp = head;
    while (temp->next != head)
    {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
  }
}

void insertMiddle(int value, int index)
{
  struct Node *newnode = createNode(value);
  if (head == NULL)
  {
    newnode->next = newnode;
    head = newnode;
  }
  else
  {
    struct Node *temp = head;
    int i = 1;
    while (temp->next != head && i < index - 1)
    {
      temp = temp->next;
      i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
  }
}

void deleteFirst()
{
  if (head == NULL)
  {
    printf("\nLinkedlist is empty\n");
  }
  else if (head->next == head)
  {
    free(head);
    head = NULL;
  }
  else
  {
    struct Node *temp = head, *last = head;
    while (last->next != head)
    {
      last = last->next;
    }
    head = head->next;
    last->next = head;
    free(temp);
  }
}

void deleteLast()
{
  if (head == NULL)
  {
    printf("\nLinkedlist is empty\n");
  }
  else if (head->next == head)
  {
    free(head);
    head = NULL;
  }
  else
  {
    struct Node *last = head;
    while (last->next->next != head)
    {
      last = last->next;
    }
    struct Node *temp = last->next;
    last->next = last->next->next;
    free(temp);
  }
}

void deleteMiddle(int index)
{
  if (head == NULL)
  {
    printf("\nLinkedlist is empty\n");
  }
  else if (head->next == head)
  {
    free(head);
    head = NULL;
  }
  else
  {
    struct Node *temp = head;
    int i = 1;
    while (temp->next != head && i < index - 2)
    {
      temp = temp->next;
      i++;
    }
    struct Node *q = temp->next;
    temp->next = temp->next->next;
    free(q);
  }
}

void display()
{
  if (head == NULL)
  {
    printf("Linkedlist is empty\n");
    return;
  }
  struct Node *temp = head;
  printf("\nElement of Linkedlist\n");
  do
  {
    printf("%d  ", temp->data);
    temp = temp->next;
  } while (temp != head);
}
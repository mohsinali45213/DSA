#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *prev;
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
  newnode->prev = NULL;
  return newnode;
}

void insertFirst(int value)
{
  struct Node *newnode = createNode(value);
  if (head != NULL)
  {
    head->prev = newnode;
  }
  newnode->next = head;
  head = newnode;
}

void insertLast(int value)
{

  struct Node *newnode = createNode(value);
  struct Node *temp = head;
  if (head == NULL)
  {
    head = newnode;
  }
  else
  {
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
  }
}

void insertMiddle(int value, int index)
{
  struct Node *newnode = createNode(value);
  struct Node *temp = head;
  if (head == NULL)
  {
    head = newnode;
  }
  else
  {
    int i = 1;
    while (temp->next != NULL && i < index - 1)
    {
      temp = temp->next;
      i++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev= newnode;
    temp->next = newnode;
  }
}

void deleteFirst()
{
  struct Node *temp = head;
  if (head == NULL)
  {
    printf("\nLinkedList is empty\n");
  }
  else if (temp->next == NULL)
  {
    free(temp);
    head = NULL;
  }
  else
  {
    head = temp->next;
    head->prev = NULL;
    free(temp);
  }
}

void deleteLast()
{
  struct Node *temp = head;
  if (head == NULL)
  {
    printf("\nLinkedList is empty\n");
  }
  else if (temp->next == NULL)
  {
    free(temp);
    head = NULL;
  }
  else
  {
    while (temp->next->next != NULL)
    {
      temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
  }
}

void deleteMiddle(int index)
{
  struct Node *temp = head;
  if (head == NULL)
  {
    printf("\nLinkedList is empty\n");
  }
  else if (temp->next == NULL)
  {
    free(temp);
    head = NULL;
  }
  else
  {
    int i = 1;
    while (temp->next != NULL && i < index - 1)
    {
      temp = temp->next;
      i++;
    }
    struct Node *q = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    free(q);
  }
}

void display()
{
  if (head == NULL)
  {
    printf("\nLinkedList is empty\n");
  }
  else
  {
    struct Node *temp = head;
    printf("\nElement : \n");
    while (temp->next!= NULL)
    {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("%d ",temp->data);
    printf("\n Reverse Element : ");
    while (temp != NULL)
    {
      printf("%d ", temp->data);
      temp = temp->prev;
    }
    printf("\n");
  }
}
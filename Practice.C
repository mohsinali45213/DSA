#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};

struct Node *createNode(int value)
{
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  if (newnode == NULL)
  {
    printf("Memory allocation fail...");
    exit(1);
  }
  newnode->data = value;
  newnode->next = NULL;
  return newnode;
}

void insertFirst(struct Node **head, int value)
{
  struct Node *newnode = createNode(value);
  newnode->next = *head;
  *head = newnode;
}

void insertLast(struct Node **head, int value)
{
  struct Node *newnode = createNode(value);
  struct Node *temp = *head;
  if (*head == NULL)
  {
    *head = newnode;
    return;
  }
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newnode;
}

void insertMiddle(struct Node **head, int value, int index)
{
  struct Node *newnode = createNode(value);
  struct Node *temp = *head;
  if (*head == NULL)
  {
    *head = newnode;
    return;
  }
  int i = 1;
  while (temp->next != NULL && i < index - 1)
  {
    temp = temp->next;
    i++;
  }
  newnode->next = temp->next;
  temp->next = newnode;
}

void deleteFirst(struct Node **head)
{
  struct Node *temp = *head;
  if (*head == NULL)
  {
    printf("\nLinkedList is empty");
    return;
  }
  else
  {
    *head = temp->next;
  }
  free(temp);
}

void deleteLast(struct Node **head)
{
  struct Node *temp = *head;
  if (*head == NULL)
  {
    printf("\nLinkedList is empty");
    return;
  }

  if (temp->next == NULL)
  {
    free(temp);
    *head = NULL;
  }
  else
  {
    while (temp->next->next != NULL)
    {
      temp = temp->next;
    }
  }
  free(temp->next);
  temp->next = NULL;
}

void deleteMiddle(struct Node **head, int index)
{
  struct Node *temp = *head;
  if (*head == NULL)
  {
    printf("\nLinkedList is empty");
    return;
  }
  if (index == 0)
  {
    free(temp);
    *head = NULL;
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
    temp->next = q->next;
    free(q);
  }
}

void display(struct Node *head)
{
  if (head == NULL)
  {
    printf("\nLinkedlist is Empty");
    return;
  }
  printf("\nElement : ");
  while (head != NULL)
  {
    printf("%d  ", head->data);
    head = head->next;
  }
}

int main()
{
  // head is a pointer of Node structure
  // Use to store address of first node
  struct Node *head = NULL;
  int choice, value, index;
  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Insert at the middle\n");
    printf("4. Delete at the first\n");
    printf("5. Delete at the end\n");
    printf("6. Delete at the middle\n");
    printf("7. Display the list\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value to insert: ");
      scanf("%d", &value);
      insertFirst(&head, value);
      display(head);
      break;
    case 2:
      printf("Enter value to insert: ");
      scanf("%d", &value);
      insertLast(&head, value);
      display(head);
      break;
    case 3:
      printf("Enter value to insert: ");
      scanf("%d", &value);
      printf("Enter index to insert: ");
      scanf("%d", &index);
      insertMiddle(&head,value,index);
      display(head);
      break;
    case 4:
      deleteFirst(&head);
      display(head);
      break;
    case 5:
      deleteLast(&head);
      display(head);
      break;
    case 6:
      printf("Enter index to delete: ");
      scanf("%d", &index);
      deleteMiddle(&head, index);
      display(head);
      break;
    case 7:
      display(head);
      break;
    case 8:
      printf("Exiting the program.\n");
      exit(0);
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }
  free(head);
  return 0;
}

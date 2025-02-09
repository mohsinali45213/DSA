#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *createnode(int value)
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

int main()
{
  struct Node *head = NULL;
  int choice, index, value;

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
      insertAtFirst(&head, value);
      traversalLinkedList(head);
      break;
    case 2:
      printf("Enter value to insert: ");
      scanf("%d", &value);
      insertAtEnd(&head, value);
      traversalLinkedList(head);
      break;
    case 3:
      printf("Enter value to insert: ");
      scanf("%d", &value);
      printf("Enter index to insert: ");
      scanf("%d", &index);
      insertAtMiddle(&head, index, value);
      traversalLinkedList(head);
      break;
    case 4:
      deleteAtFirst(&head);
      traversalLinkedList(head);
      break;
    case 5:
      deleteAtEnd(&head);
      traversalLinkedList(head);
      break;
    case 6:
      printf("Enter index to delete: ");
      scanf("%d", &index);
      deleteAtMiddle(&head, index);
      traversalLinkedList(head);
      break;
    case 7:
      traversalLinkedList(head);
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
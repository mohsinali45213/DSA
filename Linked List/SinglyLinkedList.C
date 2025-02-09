#include <stdio.h>
#include <stdlib.h>
// Structure for create node
struct Node
{
  int data;
  struct Node *next;
};

// Create newnode
struct Node *createnode(int value)
{
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  if (newnode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  newnode->data = value;
  newnode->next = NULL;
  return newnode;
}

// Inset on first position
void insertAtFirst(struct Node **head, int value)
{
  // Create newnode using createnode fuction create node function will create node with provided value
  // head is a address of *head
  // *head is a address of original node which are already exist in linkedlist
  // **head is a value of current original node not a address
  struct Node *newnode = createnode(value);
  newnode->next = *head;
  *head = newnode;
}

// Inset on last position
void insertAtEnd(struct Node **head, int value)
{
  // head is a address of *head
  // *head is a address of original node which are already exist in linkedlist
  // **head is a value of current original node not a address
  struct Node *newnode = createnode(value);
  struct Node *p = *head;
  if (*head == NULL)
  {
    *head = newnode;
    return;
  }

  while (p->next != NULL)
  {
    p = p->next;
  }
  p->next = newnode;
}

// Inset on middle position
void insertAtMiddle(struct Node **head, int index, int value)
{
  // head is a address of *head
  // *head is a address of original node which are already exist in linkedlist
  // **head is a value of current original node not a address
  struct Node *newnode = createnode(value);
  struct Node *p = *head;
  if (*head == NULL)
  {
    *head = newnode;
    return;
  }
  int i = 1;

  while (i <= index - 1 && p->next != NULL)
  {
    p = p->next;
    i++;
  }
  newnode->next = p->next;
  p->next = newnode;
}

// Delete on first position
void deleteAtFirst(struct Node **head)
{
  struct Node *p = *head;
  if (*head == NULL)
  {
    printf("\nLinkedList is empty");
    return;
  }
  else
  {
    *head = p->next;
  }
  free(p);
}
void deleteAtEnd(struct Node **head)
{
  // Check if the list is empty
  if (*head == NULL)
  {
    printf("\nLinkedList is empty");
    return;
  }

  struct Node *p = *head;

  // If there is only one node in the list
  if (p->next == NULL)
  {
    free(p);   // Free the last node explicitly
    *head = NULL; // Set head to NULL to mark the list as empty
    return;
  }

  // Traverse the list to find the last node and its previous node
  while (p->next->next != NULL)
  {
    p = p->next;
  }

  // Now, `p` is the second-to-last node
  free(p->next);  // Free the last node from the heap
  p->next = NULL; // Set the next pointer of the second last node to NULL
}

// Delete on middle position
void deleteAtMiddle(struct Node **head, int index)
{
  // Check if the list is empty
  if (*head == NULL)
  {
    printf("\nLinkedList is empty");
    return;
  }

  struct Node *p = *head;

  // If there is only one node in the list
  if (p->next == NULL)
  {
    free(p);      // Free the last node explicitly
    *head = NULL; // Set head to NULL to mark the list as empty
    return;
  }

  // Special case: If the node to delete is the first node (position = 0)
  if (index == 0)
  {
    *head = p->next; // Move the head to the next node
    free(p);         // Free the first node
    return;
  }
  int i = 0;
  while (p->next != NULL && i < index - 1)
  {
    p = p->next;
    i++;
  }
  // Q is node to be deleted
  struct Node *q = p->next;
  p->next = p->next->next;
  free(q);
}

// Display linkedlist
void traversalLinkedList(struct Node *head)
{
  if (head == NULL)
  {
    printf("LinkedList is empty");
  }
  else
  {
    printf("\nELEMENTS : ");
    while (head != NULL)
    {
      printf("%d ", head->data);
      head = head->next;
    }
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

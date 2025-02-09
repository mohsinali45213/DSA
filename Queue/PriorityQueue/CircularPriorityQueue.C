#include <stdio.h>
#define size 3

struct Queue
{
  int value;
  int priority;
} pq[size];

int front = -1, rear = -1;

void insertion(int, int);
void deletion();
void display();

int main()
{
  int item, op, priority;
  do
  {
    printf("\n1:Insertion\n");
    printf("2:Deletion\n");
    printf("3:Display\n");
    printf("4:Exit\n");
    printf("\nEnter your choice (1-4): ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      printf("\nEnter element to insert: ");
      scanf("%d", &item);
      printf("Enter priority: ");
      scanf("%d", &priority);
      insertion(item, priority);
      break;
    case 2:
      deletion();
      break;
    case 3:
      display();
      break;
    case 4:
      printf("\nExiting...\n");
      break;
    default:
      printf("\nInvalid choice! Try again.\n");
    }
  } while (op != 4);

  return 0;
}

void insertion(int item, int priority)
{
  if ((rear + 1) % size == front)
  {
    printf("\nQueue is overflow\n");
    return;
  }

  if (front == -1)
  {
    front = rear = 0;
    pq[rear].value = item;
    pq[rear].priority = priority;
    return;
  }
  
  int i = rear;
  rear = (rear + 1) % size;
  while (i != front - 1 && pq[i].priority < priority)
  {
    pq[(i + 1) % size] = pq[i];
    i = (i - 1 + size) % size;
  }

  pq[(i + 1) % size].value = item;
  pq[(i + 1) % size].priority = priority;
}

void deletion()
{
  if (front == -1)
  {
    printf("\nQueue is underflow\n");
    return;
  }

  printf("%d(%d) is Deleted\n", pq[front].value, pq[front].priority);

  if (rear == front) 
  {
    front = rear = -1;
  }
  else
  {
    front = (front + 1) % size;
  }
}

void display()
{
  if (front == -1)
  {
    printf("\nQueue is Empty\n");
    return;
  }

  int i = front;

  while (1)
  {
    printf("%d(%d)  ", pq[i].value, pq[i].priority);
    if (i == rear)
      break;
    i = (i + 1) % size;
  }
  printf("\n");
}

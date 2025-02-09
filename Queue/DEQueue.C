#include <stdio.h>
#include <conio.h>
#define size 5
int dq[size], front = -1, rear = -1;
void insertFirst(int);
void insertLast(int);
void deleteFirst();
void deleteLast();
void display();

int main()
{
  int item, op;
  do
  {
    printf("\n1:InsertFirst\n");
    printf("2:InsertLast\n");
    printf("3:deleteFirst\n");
    printf("4:deleteLast\n");
    printf("5:Display\n");
    printf("6:Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      printf("\nEnter element to insert : ");
      scanf("%d", &item);
      insertFirst(item);
      break;
    case 2:
      printf("\nEnter element to insert : ");
      scanf("%d", &item);
      insertLast(item);
      break;
    case 3:
      deleteFirst();
      break;
    case 4:
      deleteLast();
      break;
    case 5:
      display();
      break;
    }
  } while (op < 6);
}

// Insert First
void insertFirst(int item)
{
  if ((front == 0 && rear == size - 1) || (front == rear + 1))
  {
    printf("\nQueue is overflow\n");
    return;
  }
  if (front == -1)
  {
    front = 0;
    rear = 0;
  }
  else if (front == 0)
  {
    front = size - 1;
  }
  else
  {
    front--;
  }
  dq[front] = item;
}
void insertLast(int item)
{
  if ((front == 0 && rear == size - 1) || (front == rear + 1))
  {
    printf("\nQueue is overflow\n");
    return;
  }
  if (front == -1)
  {
    front = 0;
    rear = 0;
  }
  else if (rear == size - 1)
  {
    rear = 0;
  }
  else
  {
    rear++;
  }
  dq[rear] = item;
}
void deleteFirst()
{
  if (front == -1)
  {
    printf("\nQueue is Empty\n");
    return;
  }
  printf("\n%d is Deleted\n", dq[front]);
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else if (front == size - 1)
  {
    front = 0;
  }
  else
  {
    front++;
  }
}
void deleteLast()
{
  if (front == -1)
  {
    printf("\nQueue is Empty\n");
    return;
  }
  printf("\n%d is Deleted\n", dq[rear]);
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else if (rear == 0)
  {
    rear = size - 1;
  }
  else
  {
    rear--;
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
    printf("%d  ", dq[i]);
    if (i == rear)
      break;
    i = (i + 1) % size;
  }
}
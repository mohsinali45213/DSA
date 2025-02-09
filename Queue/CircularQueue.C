#include <stdio.h>
#include <conio.h>
#define size 4
int cq[size], front = -1, rear = -1;
void cqInsert(int);
void cqDelete();
void cqDisplay();

int main()
{
  int item, op;
  do
  {
    printf("\n1 : Insertion\n");
    printf("2 : Deletion\n");
    printf("3 : Display\n");
    printf("4 : Exit\n\n");
    printf("Enter option : ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      printf("\nEnter element to be inserted\n");
      scanf("%d", &item);
      cqInsert(item);
      break;
    case 2:
      cqDelete();
      break;
    case 3:
      cqDisplay();
      break;
    }
  } while (op < 4);
  return 0;
}

void cqInsert(int item)
{
  if (((front == 0) && (rear == size - 1)) || (front == rear + 1)) // if ((rear + 1) % size == front)
  {
    printf("\nQueue is full\n");
    return;
  }
  if (front == -1)
  {
    front = 0;
    rear = 0;
  }
  else
  {
    rear = (rear + 1) % size;
  }
  // else if (rear == size - 1)
  // {
  //   rear = 0;
  // }
  // else
  // {
  //   rear++;
  // }

  cq[rear] = item;
}

void cqDelete()
{
  if (front == -1)
  {
    printf("\nQueue is empty\n");
    return;
  }
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    front = (front + 1) % size;
  }
  // else if (front == size - 1)
  // {
  //   front = 0;
  // }
  // else
  // {
  //   front++;
  // }
}

void cqDisplay()
{
  if (front == -1)
  {
    printf("\nQueue is empty\n");
    return;
  }
  printf("\nElement of queue\n");
  // if (front <= rear)
  // {
  //   for (int i = front; i <= rear; i++)
  //   {
  //     printf("%d ", cq[i]);
  //   }
  // }
  // else
  // {
  //   printf("\nElement of queue\n");
  //   for (int i = front; i <= size - 1; i++)
  //   {
  //     printf("%d ", cq[i]);
  //   }
  //   for (int i = 0; i <= rear; i++)
  //   {
  //     printf("%d ", cq[i]);
  //   }
  // }

  int i = front;
  while (1)
  {
    printf("%d  ", cq[i]);
    if (i == rear)
    {
      break;
    }
    i = (i + 1) % size;
  }
}
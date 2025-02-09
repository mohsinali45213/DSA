#include <stdio.h>
#include <conio.h>
#define size 5

struct PQueue
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
  int op, item, priority;
  do
  {
    printf("\n1:Insertion\n");
    printf("2:Deletion\n");
    printf("3:Display\n");
    printf("4:Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      printf("\nEnter element to insert : ");
      scanf("%d", &item);
      printf("Enter priority :");
      scanf("%d", &priority);
      insertion(item, priority);
      break;
    case 2:
      deletion();
      break;
    case 3:
      display();
      break;
    }
  } while (op != 4);
}

void insertion(int item, int priority)
{
  if (rear == size - 1)
  {
    printf("\nQueue is overflow\n");
    return;
  }
  if (front == -1)
  {
    front = 0;
    rear = 0;
    pq[rear].value = item;
    pq[rear].priority = priority;
    return;
  }
  else
  {
    int i=rear;
    while (front<=i && pq[i].priority>priority)
    {
        pq[i+1]=pq[i];
      i--;
    }
    pq[i+1].value=item;
    pq[i+1].priority=priority;
    rear++;
  }
}

void deletion()
{
  if(front==-1)
  {
    printf("\nQueue is Empty\n");
  }
  printf("\n%d is Deleted which priority is %d\n",pq[front].value,pq[front].priority);
  if(front==rear){
    front=-1;
    rear=-1;
  }
  else{
    front++;
  }
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nPriority Queue elements:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("Value: %d, Priority: %d\n", pq[i].value, pq[i].priority);
    }
}
#include <stdio.h>
#define max 5
int rear = -1;
int front = -1;
int queue[max];

int isEmpty()
{
  return front == -1 || front > rear;
}

int isFull()
{
  return rear == max - 1;
}

void Insert(int value)
{
  if (isFull())
  {
    printf("\nQUEUE IS FULL");
    return;
  }
  if (front == -1)
    front = 0;
  rear++;
  queue[rear] = value;
}

int Delete()
{
  if (isEmpty())
  {
    printf("\nQUEUE IS EMPTY");
    return 0;
  }
  int no = queue[front];
  front++;
  if (front > rear)
  {
    front = -1;
    rear = -1;
  }
  return no;
}

int main()
{
  int node;
  int i = 0;
  int visited[] = {0, 0, 0, 0, 0, 0, 0};
  int a[7][7] = {
      {0, 1, 1, 1, 0, 0, 0},
      {1, 0, 1, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 0},
      {1, 0, 1, 0, 1, 0, 0},
      {0, 0, 1, 1, 0, 1, 1},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1, 0, 0}};
  printf("%d ", i);
  visited[i] = 1;
  Insert(i);

  while (!isEmpty())
  {
    node = Delete();
    for (int j = 0; j < 7; j++)
    {
      if (a[node][j] == 1 && visited[j] == 0)
      {
        printf("%d ", j);
        visited[j] = 1;
        Insert(j);
      }
    }
  }
}

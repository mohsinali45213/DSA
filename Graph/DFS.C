#include <stdio.h>

int visited[] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 0, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int node)
{
  int j;
  printf("%d ", node);
  visited[node] = 1;
  for (j = 0; j < 7; j++)
  {
    if (a[node][j] == 1 && visited[j]==0)
    {
      DFS(j);
    }
  }
}
int main()
{
  DFS(0);
}

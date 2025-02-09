#include <stdio.h>

int main()
{
  int arr[] = {45, 32, 56, 12, 42, 12, 45, 66, 121}, search, f = 0;
  int size = sizeof(arr) / sizeof(int);
  printf("ENTER SEARCH ELEMENT : ");
  scanf("%d", &search);

  for (size_t i = 0; i < size - 1; i++)
  {
    if (arr[i] == search)
    {
      printf("\nElement %d store on index %d", search, i);
      f = 1;
    }
  }
  if (f == 0)
  {
    printf("Element not found");
  }
}
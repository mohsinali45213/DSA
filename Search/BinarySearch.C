#include <stdio.h>

int main()
{
  // Array must be sorted
  int arr[] = {1, 2, 44, 55, 65, 78, 81, 97}, search, f = 0;
  int high = (sizeof(arr) / sizeof(int)) - 1;
  int low = 0;
  int mid = 0;
  printf("ENTER SEARCH ELEMENT : ");
  scanf("%d", &search);

  while (low <= high)
  {
    mid = (low + high) / 2;
    if (search == arr[mid])
    {
      printf("Element %d store on index %d", search, mid);
      f = 1;
    }
    if (search > arr[mid])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  if (f == 0)
  {
    printf("Element not found");
  }
}
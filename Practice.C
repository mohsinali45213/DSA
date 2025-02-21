#include <stdio.h>
#include <conio.h>
void quicksort(int[], int, int);
int partition(int[], int, int);
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int arr[] = {99, 77, 55, 88, 44, 66, 33, 11, 22, 44};
  int size = sizeof(arr) / sizeof(int);
  printArray(arr, size);
  quicksort(arr, 0, size - 1);
  printArray(arr, size);
}

void quicksort(int arr[], int low, int high)
{
  int partitionIndex;
  if (low < high)
  {
    partitionIndex = partition(arr, low, high);
    quicksort(arr, low, partitionIndex - 1);
    quicksort(arr, partitionIndex + 1, high);
  }
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[low];
  int i = low + 1;
  int j = high;
  int temp;

  while (i < j)
  {
    while (arr[i] <= pivot)
    {
      i++;
    }
    while (arr[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  if(arr[j]<arr[low])
  {
    temp = arr[low];
    arr[low] = arr[j];
    arr[j]= temp;
  }
  return j ;
}
#include <stdio.h>
#include <conio.h>
void merge(int[], int, int, int);
void mergeSort(int[], int, int);
void display(int[], int);
int main()
{
  int arr[] = {44, 88, 55, 32, 32, 90, 11, 32, 12, 98, 26};
  int size = sizeof(arr) / sizeof(int);
  display(arr, size);
  mergeSort(arr, 0, size - 1);
  display(arr, size);
}

void mergeSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

void merge(int arr[], int low, int mid, int high)
{
  int i, j, k, temp[high + 1];
  i = low;
  k = low;
  j = mid + 1;
  while (i <= mid && j <= high)
  {
    if (arr[i] < arr[j])
    {
      temp[k] = arr[i];
      i++;
      k++;
    }
    else
    {
      temp[k] = arr[j];
      j++;
      k++;
    }
  }
  while (i <= mid)
  {
    temp[k] = arr[i];
    i++;
    k++;
  }
  while (j <= high)
  {
    temp[k] = arr[j];
    j++;
    k++;
  }
  for (i = low; i <= high; i++)
  {
    arr[i] = temp[i];
  }
}

void display(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}
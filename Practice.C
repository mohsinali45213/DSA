#include <stdio.h>
#include <conio.h>
void display(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}

void merge(int arr[], int low, int mid, int high)
{
  int i, j, k, temp[high + 1];
  i = low;
  j = mid + 1;
  k = low;
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
  for (i = low; i <=high; i++)
  {
    arr[i] = temp[i];
  }
}

void mergesort(int arr[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

int main()
{
  int arr[] = {80, 70, 70, 54, 23, 27, 12, 56, 43};
  int size = sizeof(arr) / sizeof(int), j, key, i;
  display(arr, size);
  mergesort(arr, 0, size - 1);
  display(arr, size);
}
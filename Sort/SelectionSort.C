#include <stdio.h>
#include <conio.h>
void display(int arr[],int size){
  for (size_t i = 0; i < size; i++)
  {
    printf("%d  ",arr[i]);
  }
  
}
int main()
{
  int arr[] = {30, 24, 45, 21, 67, 33, 78, 12, 45}, i, j;
  int size = sizeof(arr) / sizeof(int);
  printf("\nArray Befor Sorting\n");
  display(arr,size);
  for (i = 0; i < size - 1; i++)
  {
    for (j = i + 1; j < size; j++)
    {
      if (arr[i] > arr[j])
      {
        int t = arr[j];
        arr[j] = arr[i];
        arr[i] = t;
      }
    }
  }
  printf("\nArray After Sorting\n");
  display(arr,size);
}
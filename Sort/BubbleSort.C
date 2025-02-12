#include<stdio.h>
#include<conio.h>
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
  for(i=0;i<size-1;i++)
  {
    for(j=0;j<size-1-i;j++)
    {
      if(arr[j]>arr[j+1])
      {
        int t = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = t;
      }
    }
  }
  printf("\nArray After Sorting\n");
  display(arr,size);
}
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
  int arr[] = {30,40,20,60,10,20,60},i,j,item;
  int size = sizeof(arr) / sizeof(int);
  printf("\nArray Befor Sorting\n");
  display(arr,size);
  for(i=1;i<size;i++)
  {
    item = arr[i];
    j=i-1;
    while (j>=0 && item<arr[j])
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1] = item;
  }
  printf("\nArray After Sorting\n");
  display(arr,size);
}
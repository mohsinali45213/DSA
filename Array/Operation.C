#include <stdio.h>
#include <stdlib.h>
struct myArray
{
  int *arr;
  int size;
  int max;
};

void insertion(struct myArray *num);
void deletion(struct myArray *num);
void display(struct myArray *num);
int main()
{
  struct myArray num;

  num.arr = (int *)malloc(20 * sizeof(int));
  num.max = 20;
  num.size = 0;

  if (num.arr == NULL)
  {
    printf("Memory allocation failed\n");
    return 1;
  }

  printf("\nENTER THE SIZE OF ELEMENTS DO YOU WANNA INSERTED : ");
  scanf("%d", &num.size);

  for (int i = 0; i < num.size; i++)
  {
    printf("ENTER ELEMENT %d : ", i + 1);
    scanf("%d", &num.arr[i]);
  }

  display(&num);

  int choice;
  do
  {
    printf("\nInsertion : 1");
    printf("\nDeletion : 2");
    printf("\nExit : 3");
    printf("\nEnter Your Choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      insertion(&num);
      break;
    case 2:
      deletion(&num);
      break;
    case 3:
      return 0;
    default:
      printf("\nInvalid Input");
      break;
    }
  } while (choice < 4);

  free(num.arr);
}

void insertion(struct myArray *num)
{
  int pos = 0, element = 0;
  printf("\nENTER ELEMENT DO YOU WANNA INSERT : ");
  scanf("%d", &element);
  printf("ENTER POSITION : ");
  scanf("%d", &pos);

  if (pos < 0 || pos - 1 >= num->size + 1)
  {
    printf("Insert is not possible...");
  }
  else
  {
    for (int i = num->size; i > pos - 1; i--)
    {
      (num->arr)[i] = (num->arr)[i - 1];
    }
    (num->arr)[pos - 1] = element;
    num->size++;

    display(num);
  }
}
void deletion(struct myArray *num)
{
  int pos;
  printf("ENTER POSITION : ");
  scanf("%d", &pos);
  if(pos<0 || pos-1>=num->size){
    printf("Deletion is not possible...");
  }else{
    for (int  i = pos-1; i < num->size-1; i++)
    {
      (num->arr)[i] = (num->arr)[i+1];
    }
    num->size--;
    
  }
  display(num);
}
void display(struct myArray *num)
{
  printf("ELEMENTS ARE : ");
  for (int i = 0; i < (*num).size; i++)
  {
    printf("%d ", (num->arr)[i]);
  }
}
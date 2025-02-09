#include <stdio.h>
#define max 5
int top = 0;
int stack[max];

void push();
void pop();
void display();
int main()
{
  int choice;
  do
  {
      printf("\nPUSH : 1");
    printf("\nPOP : 2");
    printf("\nDisplay : 3");
    printf("\nEXIT : 4");
    printf("\nENTER YOUR CHOICE : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      push();
      display();
      break;
    case 2:
      pop();
      display();
      break;
    case 3:
      display();
      break;
    case 4:
      return 0;
    default:
      printf("\nINVALID INPUT");
    }
  } while (choice <= 4);
}

void push()
{
  int value;
  printf("\nENTER THE VALUE : ");
  scanf("%d", &value);
  if (top > max)
  {
    printf("\nSTACK IS OVERFLOW");
  }
  else
  {
    stack[top] = value;
    top++;
  }
}

void pop(){
  if(top==0){
    printf("\nSTACK IS EMPTY");
  }else{
    int value = stack[top-1];
    printf("\n%d IS DELETED",value);
    stack[top] = 0;
    top--;
  }
}

void display()
{
  for (int i = 0; i < top; i++)
  {
    printf("\nELEMENTS : %d", stack[i]);
  }
}
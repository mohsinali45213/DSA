//Programming to implement stack using array

#include <stdio.h>
#include <conio.h>
#define MAX 5
int arr[MAX], top = -1;
void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }
    arr[++top] = item;
}
void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Deleted item is %d\n", arr[top--]);
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (i = top; i >= 0; i--)
        printf("%d\n", arr[i]);
}
void main()
{
    int item, op;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    }while (op != 4);
    getch();
}
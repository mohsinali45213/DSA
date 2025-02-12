// Program to implement linear queue using array
#include <stdio.h>
#include <conio.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void insert(int);
void del();
void display();
void main()
{
    int op,item;
    // clrscr();
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your option:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter the element to be inserted:");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
        }
    }while(op!=4);
    getch();
}
void insert(int item)
{
    if(rear==MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    if(front==-1)
    { 
      front=0;
    }

    rear=rear+1;
    queue[rear]=item;
}
void del()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted element is %d\n",queue[front]);
    if(front==rear)
    {
        front= -1;
        rear=-1;
    }
        front=front+1;
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    for(i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
}

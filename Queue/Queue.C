#include <stdio.h>
#define max 5
int rear = -1;
int front = -1;
int queue[max];

void Insert();
void Delete();
void Display();

int main()
{
    int choice;
    do
    {
        printf("\n\nMENU:");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            return 0;
        default:
            printf("\nINVALID CHOICE");
        }
        Display();
    } while (choice < 4);

    return 0;
}

void Insert()
{
    int value;
    if (rear == max - 1)
    {
        printf("\nQUEUE IS FULL");
        return;
    }
    printf("\nENTER VALUE: ");
    scanf("%d", &value);
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
    printf("\n%d INSERTED INTO THE QUEUE", value);
}

void Delete()
{
    if (front == -1 || front > rear)
    {
        printf("\nQUEUE IS EMPTY");
        return;
    }
    printf("\n%d IS DELETED", queue[front]);
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void Display()
{
    if (front == -1)
    {
        printf("\nQUEUE IS EMPTY");
        return;
    }
    printf("\nQUEUE ELEMENTS:");
    for (int i = front; i <= rear; i++)
    {
        printf(" %d", queue[i]);
    }
}

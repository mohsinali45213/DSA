// Program to finde Length Cancate Compare and Copy of String without using Library Function
#include <stdio.h>
#include <string.h>
void length(char[]);
void concate(char[], char[]);
void compare(char[], char[]);
void copy(char[], char[]);

void main()
{
    char str1[100], str2[100];
    int op;
    do 
    {
        printf("\n\n1. Length of String\n2. Concatenation of String\n3. Comparison of String\n4. Copy of String\n5. Exit\nEnter your choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the string: ");
            scanf("%s", str1);
            length(str1);
            break;
        case 2:
            printf("Enter the first string: ");
            scanf("%s", str1);
            printf("Enter the second string: ");
            scanf("%s", str2);
            concate(str1, str2);
            break;
        case 3:
            printf("Enter the first string: ");
            scanf("%s", str1);
            printf("Enter the second string: ");
            scanf("%s", str2);
            compare(str1, str2);
            break;
        case 4:
            printf("Enter the string: ");
            scanf("%s", str1);
            copy(str1, str2);
            break;
        }  
    } while (op != 5);
}

void length(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    printf("Length of the string is: %d", i);
}

void concate(char str1[], char str2[])
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        i++;
    }
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    printf("Concatenated string is: %s", str1);
}

void compare(char str1[], char str2[])
{
    int i = 0, flag = 0;
    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0)
    {
        printf("Strings are equal");
    }
    else
    {
        printf("Strings are not equal");
    }
}


void copy(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
    printf("Copied string is: %s", str2);
}

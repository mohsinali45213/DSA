// Program to swap two numbers using call by value and call by reference
#include <stdio.h>
#include <conio.h>
void swap(int, int);
void swapByReference(int *, int *);

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("After swapping in main function: a = %d, b = %d\n", a, b);
    swapByReference(&a, &b);
    printf("After swapping in main function: a = %d, b = %d\n", a, b);
    return 0;
}
void swap(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("After swapping in swap function: a = %d, b = %d\n", a, b);
}
void swapByReference(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("After swapping in swapByReference function: a = %d, b = %d\n", *a, *b);
}
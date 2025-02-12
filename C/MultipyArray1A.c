// Program to multiply two matrices
#include <stdio.h>
#include <conio.h>

int main()
{
    int a[3][3], b[3][3], c[3][3], m, n, i, j, p, q, k;
    printf("Enter the number of rows and columns of first matrix\n");
    scanf("%d%d", &m, &n);
    printf("Enter the elements of first matrix\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {          
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the number of rows and columns of second matrix\n");
    scanf("%d%d", &p, &q);
    if (n != p)
    {
        printf("The matrices cannot be multiplied with each other\n");
        return 0;
    }
    printf("Enter the elements of second matrix\n");
    for (i = 0; i < p; i++)
     {
           for (j = 0; j < q; j++)
           {
                scanf("%d", &b[i][j]);
            }
     }

    for (i = 0; i < m; i++)
    {  
        for (j = 0; j < q; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                    c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("The product of the two matrices is\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    getch();
    return 0;
}
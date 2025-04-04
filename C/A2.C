#include <stdio.h>

int main()
{
  int a[3][3], b[3][3], c[3][3], i, j, m, n, p, q, k;
  printf("Enter m n\n");
  scanf("%d %d", &m, &n);
  printf("Enter p q\n");
  scanf("%d %d", &p, &q);

  if (n != p)
  {
    printf("Multiplication is not possible");
    return 0;
  }
  else
  {
    printf("Enter Matrix A\n");
    for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
      {
        scanf("%d", &a[i][j]);
      }
    }
    printf("Enter Matrix B\n");
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
          c[i][j] = c[i][j] + a[i][k] * b[k][j];
        }
      }
    }

    for (i = 0; i < m; i++)
    {
      for (j = 0; j < q; j++)
      {
        printf("%d", c[i][j]);
      }
      printf("\n");
    }
  }
}
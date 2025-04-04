
#include <stdio.h>
void slength(char[]);
void strcom(char[], char[]);
void strcon(char[], char[]);

int main()
{
  char s1[50], s2[50];
  int op;
  do
  {
    printf("\n\nMENU:");
    printf("\n1. Strlen");
    printf("\n2. StrCompare");
    printf("\n3. StrConcat");
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &op);
    fflush(stdin); // Clear the input buffer to avoid issues with gets()
    switch (op)
    {
    case 1:
      printf("\nEnter String :");
      gets(s1);
      slength(s1);
      break;
    case 2:
      printf("\nEnter String 1 :");
      gets(s1);
      printf("\nEnter String 2 :");
      gets(s2);
      strcom(s1, s2);
      break;
    case 3:
      printf("\nEnter String 1 :");
      gets(s1);
      printf("\nEnter String 2 :");
      gets(s2);
      strcon(s1, s2);
    default:
      printf("\nINVALID CHOICE");
    }
  } while (op != 4);
}

void slength(char s[50])
{
  int len = 0;
  for (int i = 0; s[i] != '\0'; i++)
  {
    len++;
  }
  printf("\nLength = %d", len);
}

void strcon(char s1[50], char s2[50])
{
  int i = 0, j = 0;
  while (s1[i] != '\0')
  {
    i++;
  }
  while (s2[j] != '\0')
  {
    s1[i] = s2[j];
    i++;
    j++;
  }
  s1[i] = '\0';
  printf("\nConcatenated String = %s", s1);
}

void strcom(char s1[50], char s2[50])
{
  int i = 0, m;
  while (s1[i] == s2[i])
  {
    if (s1[i] == '\0')
    {
      break;
    }
    i++;
  }

  m = s1[i] - s2[i];
  printf("M = %d", m);
  if (m == 0)
  {
    printf("Both string are equal");
  }
  else if (m < 0)
  {
    printf("First string appear befor sec");
  }
  else
  {
    printf("First string appear after sec");
  }
}

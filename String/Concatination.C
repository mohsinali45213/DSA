
#include <stdio.h>
#include <string.h>
int main()
{
  char str1[30] = "hello";
  char str2[] = " How Are You";
  int i;
  int j = strlen(str1);
  for (i = 0; str2[i] != '\0'; i++,j++)
  {
    str1[j] = str2[i];
  }
  str1[j] = '\0';
  printf("%s", str1);
}
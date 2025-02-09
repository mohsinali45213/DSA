
#include <stdio.h>
#include <string.h>
int main()
{
  char s1[] = "HELLO";
  char s2[] = "HELLO";
  bool flag = false;

  if (strlen(s1) == strlen(s2))
  {
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
    {
      if (s1[i] == s2[i])
      {
        flag = true;
      }
      else
      {
        flag = false;
        break;
      }
    }
  }
  else
  {
    printf("BOTH STRING ARE NOT EQUAL");
  }

  if (flag == true)
  {
    printf("BOTH STRING ARE EQUAL");
  }
  else
  {

    printf("BOTH STRING ARE NOT EQUAL");
  }
}
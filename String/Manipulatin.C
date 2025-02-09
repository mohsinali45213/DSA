#include <stdio.h>
#include <string.h>
int main()
{
  char str[] = "HELLO how ARE you";
  char str2[] = "My name is XYZ";
  printf("%s\n",str);
  printf("LENGTH : %d\n",strlen(str));
  printf("UPPER : %s\n",strupr(str));
  printf("LOWER : %s\n",strlwr(str));
  printf("CONCAT : %s\n",strcat(str,str2));
  printf("REVERSE : %s\n",strrev(str));
}
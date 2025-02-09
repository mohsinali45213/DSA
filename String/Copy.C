
# include <stdio.h>
int main(){
  char str[] = "hello";
  char newStr[10];
  int i;
  for(i = 0 ; str[i] !='\0';i++){
    newStr[i] = str[i];
  }
newStr[i] = '\0';
  printf("%s",newStr);
}
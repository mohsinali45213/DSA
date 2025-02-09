
# include <stdio.h>

int main (){
  char str[] = "hello";
  int i,l=0;

  for(i=0;str[i] !='\0';i++){
    l++;
  }

  printf("LENGTH OF STRING : %d",l);
}
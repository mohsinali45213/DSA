#include <stdio.h>
#include <string.h>

int main (){
  char s1[3][50];
  for(int i=0 ;i<3;i++){
    scanf("%s",s1[i]);
  }
  for(int i=0 ;i<3;i++){
    printf("%s\n",s1[i]);
  }
}
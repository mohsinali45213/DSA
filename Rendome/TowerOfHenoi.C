#include <stdio.h>
#include <conio.h>
void tower(int,char,char,char);
int main()
{
  int n;
  printf("Enter Number of Discs : ");
  scanf("%d",&n);
  tower(n,'A','B','C');
  return 0;
}

void tower(int n,char src,char temp,char dest){
  if(n==0){
    return;
  }
  tower(n-1,src,dest,temp);
  printf("Move disc %d from %c to %c\n",n,src,dest);
  tower(n-1,temp,src,dest);
}
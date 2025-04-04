
#include <stdio.h>
#include <math.h>
int bindec(int, int, int);

int main()
{
  int bn, dn = 0;
  printf("Enter Binary No\n");
  scanf("%d",&bn);
  dn = bindec(bn,dn,0);
  printf("%d",dn);
}

int bindec(int bn,int dn,int i)
{
  if(bn ==0)
  {
    return dn;
  }
  int r = bn%10;
  dn = dn+r*pow(2,i);
  return bindec(bn/10,dn,i+1);
}
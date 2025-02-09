#include <stdio.h>
#include <conio.h>
#include <math.h>

int bindec(int, int, int);

int main()
{
  int bn, dn = 0;
  printf("Enter Binary Number : ");
  scanf("%d", &bn);
  dn = bindec(bn, dn, 0);
  printf("Decimal equivalence : %d", dn);
  return 0;
}

int bindec(int bn, int dn, int i)
{
  int r;
  if (bn == 0)
  {
    return dn;
  }
  r = bn % 10;
  dn = dn + r * pow(2, i);
  return (bindec(bn / 10, dn, i + 1));
}

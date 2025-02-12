// Program to convert binary number to decimal number
#include <stdio.h>
#include <conio.h>
#include <math.h>
int binaryToDecimal(int,int,int);
void main()
{
    int bn,dn=0;
    printf("Enter the binary number\n");
    scanf("%d", &bn);
    dn = binaryToDecimal(bn,0,0);
    printf("The decimal equivalent of %d is %d\n", bn, dn);
    getch();
}

int binaryToDecimal(int bn,int dn,int i)
{
    int r;
    if(bn==0)
    {
        return dn;
    }
    r=bn%10;
    dn=dn+r*pow(2,i);
    return binaryToDecimal(bn/10,dn,i+1);
}



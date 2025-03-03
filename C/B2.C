#include<stdio.h>
#include <conio.h>
#include<ctype.h>
#include<string.h>
int main()
{
  char infix[20], postfix[20],s[20],sym;
  int top=-1,i=0,j=0,len;
  printf("Enter the infix expression: ");
  scanf("%s",infix);
  len=strlen(infix);
  s[++top]='#';
  for (i = 0; i < len; i++)
  {
    sym=infix[i];
    if (isalnum(sym))
    {
      postfix[j++]=sym;
    }
    else if (sym=='(')
    {
      s[++top]=sym;
    }
    else if (sym==')')
    {
      while (s[top]!='(')
      {
        postfix[j++]=s[top--];
      }
      top--;
    }
    else if(sym=='^')
    {
      s[++top]=sym;
    }
    else if(sym=='*' || sym=='/')
    {
      while (s[top]=='^' || s[top]=='*' || s[top]=='/')
      {
        postfix[j++]=s[top--];
      }
      s[++top]=sym;
    }
    else if(sym=='+' || sym=='-')
    {
      while (s[top]=='^' || s[top]=='*' || s[top]=='/' || s[top]=='+' || s[top]=='-')
      {
        postfix[j++]=s[top--];
      }
      s[++top]=sym;
    }
  }
  while (s[top]!='#')
  {
    postfix[j++]=s[top--];
  }
  postfix[j]='\0';
  printf("The postfix expression is: %s\n",postfix);
  return 0;
}
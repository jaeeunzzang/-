#include <stdio.h>
#include <stdlib.h>
#include <string.h>

type def double num;
type def struct _stack
{
  num data;
  struct stack *link;
}stack;

stack *top;

void push(num item)
{
  stack *temp=(stack*)malloc(sizeof(stack));
  temp->data=item;
  temp->link=top;
  top=temp;
}

num pop()
{
  num item;
  stack *temp=top;
  if(top==NULL)
  {
    printf("empty");
    return 0;
  }
  else
  {
    item=temp->data;
    top=temp->link;
    free(temp);
    return item;
  }
}

num Postfix(char *exp)
{
  double n1,n2;
  int value, i=0,cnt=0;
  int length=strlen(exp);
  char symbol;
  
  for(i=0;i<length;i++)
  {
    symbol=exp[i];
    if(symbol>='0'&&symbol<='9')
    {
      while(exp[i+cnt]!= '')
      {
        cnt++;
      }
      value\atol(&exp[i]);
      postfix[(*p)++]=' ';
    }
    else
    {
      push(temp);
      break;
    }
  }
  push(symbol);
}

void postfix_ope2(char*postfix, char symbol,int *p)
{
  char temp;
  while(1)
  {
    if(top==NULL)
    {
      break;
    }
    temp=(char)pop();
    if(temp=='*' ||temp=='/')
    {
      postfix[(*p)++]=temp;
      postfix[(*p)++]=' ';
    }
    else
    {
      push(temp);
      break;
    }
  }
  push(symbol);
}


      
    
      
         

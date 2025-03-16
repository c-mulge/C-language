#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

int power(int base, int exponent) 
{
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}


int
evalute (char ch, int opnd1, int opnd2)
{
  switch (ch)
    {
    case '+':
      return opnd1 + opnd2;
      break;

    case '-':
      return opnd1 - opnd2;
      break;

    case '*':
      return opnd1 * opnd2;
      break;

    case '/':
      return opnd1 / opnd2;
      break;

    case '^':
        return power(opnd1, opnd2);
        break;
     
     default:
     printf("No expression found\n"); 
    }
}

int
isoperand (char ch)
{
  if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
    {
      return 1;
    }
  return 0;
}

int
posteval (char postfix[])
{
  struct stack *stk = NULL;
  int opnd1, opnd2, result;
  char opndstk[5];
  int i = 0;
  int len = strlen (postfix);
  while (i < len)
    {
      if (isoperand (postfix[i]))
	{
	  opndstk[0] = postfix[i];
	  opndstk[1] = '\0';
	  push (stk, atoi (opndstk));
	}
      else
	{
	  opnd2 = pop (stk);
	  opnd1 = pop (stk);
	  result = evalute (postfix[i], opnd1, opnd2);
	  push (stk, result);
	}
      i++;
    }
  return pop (stk);
}

int
main ()
{
  char stk[100];
  int res;
  printf ("Enter the exprestion\n");
  scanf ("%s", stk);
  res = posteval (stk);
  printf ("Result %d \n", res);
  return 0;
}
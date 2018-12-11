#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE_MAX 1024

// Instantiation du tableau

int pile[STACK_SIZE_MAX]={0}; 


// Ajouter un élément au tableau

void push(int x)
{
  int c=0;
  while (pile[c] != 0)
  {
     c++;
  }
  pile[c]=x;
}


// Dépiler le dernier élément du tableau
int pop()
{
  int c=0;

  while (pile[c] != 0)
  {
    c++;
  }

  int dernierE=pile[c-1];
  pile[c-1]=0;
  return dernierE;
}


int main(int argc, const char **argv)
{
  int a;
  int b;

  for(int i = 1; i < argc; i++){  
     switch(*argv[i])
     {
     case '+':
       a=pop();
       b=pop();
       push(a+b);
       break;
     case '-':
       a=pop();
       b=pop();
       push(b-a);
       break;
     case '*':
       a=pop();
       b=pop();
       push(a*b);
       break;
     case '/':
       a=pop();
       b=pop();
       push(b/a);
       break;
     default:
       push(atoi(argv[i]));
       break;
     }
  }
  printf("Résultat : %d \n",pop());
  return 0;
}

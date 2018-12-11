#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE_MAX 1024

typedef struct Element Element;
struct Element
{
  int nombre;
  Element *suivant;
};

typedef struct Pile Pile;
struct Pile
{
  Element *premier;
};

// Instantiation du tableau

Pile *maPile = NULL;

// Ajouter un élément au tableau

void push(Pile *pile, int x)
{
  Element *nouveau = malloc(sizeof(*nouveau));

  if (pile == NULL || nouveau == NULL)
  {
    exit(EXIT_FAILURE);
  }

  nouveau->nombre = x;
  nouveau->suivant = pile->premier;
  pile->premier = nouveau;
}

int pop(Pile *pile)
{
  if (pile == NULL)
  {
    exit(EXIT_FAILURE);
  }

  int nombreDepile = 0;
  Element *elementDepile = pile->premier;

  if (pile != NULL && pile->premier != NULL)
  {
    nombreDepile = elementDepile->nombre;
    pile->premier = elementDepile->suivant;
    free(elementDepile);
  }

  return nombreDepile;
}


int main(int argc, const char **argv)
{
  int a;
  int b;
  Pile *maPile = malloc(STACK_SIZE_MAX);
  for(int i = 1; i < argc; i++){  
     switch(*(*(argv+i)))
     {
     case '+':
       a=pop(maPile);
       b=pop(maPile);
       push(maPile,a+b);
       break;
     case '-':
       a=pop(maPile);
       b=pop(maPile);
       push(maPile,b-a);
       break;
     case '*':
       a=pop(maPile);
       b=pop(maPile);
       push(maPile,a*b);
       break;
     case '/':
       a=pop(maPile);
       b=pop(maPile);
       push(maPile,b/a);
       break;
     default:
       push(maPile,atoi(*(argv+i)));
       break;
     }
  }
  printf("Résultat : %d \n",pop(maPile));
  return 0;
}

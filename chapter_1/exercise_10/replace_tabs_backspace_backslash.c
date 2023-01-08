#include <stdio.h>

#define TAB         9
#define BACKSPACE   8
#define BACKSLASH   92

/*
 * Replaces tabs, backspace and backslash with more explicit notations.
 */
int main()
{
  int c, b;

  while ((c = getchar()) != EOF)
  {
    if (c == TAB)
    {
      printf("\\t");
    }
    else if (c == BACKSPACE)
    {
      printf("\\b");
    }
    else if (c == BACKSLASH)
    {
      printf("\\\\");
    }
    else
    {
      putchar(c);
    }
  }
}


#include <stdio.h>

#define BLANK 32

/*
 * Prints each word in the input on a new line.
 */
int
main()
{
  char c;

  while ((c = getchar()) != EOF) {
    if (c == BLANK) {
      putchar('\n');
    } else {
      putchar(c);
    }
  }
  
  return 0;
}

#include <stdio.h>

#define BLANK   32

/*
 * Removes double spaces from input.
 */
int
main()
{
  int c, b = 0;

  while ((c = getchar()) != EOF) {
    if (c == BLANK) {
      if (!b)
        putchar(c);

      b = 1;
    } else {
      b = 0;
      putchar(c);
    }
  }
}

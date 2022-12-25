#include <stdio.h>

#define BLANK   32
#define TAB     9
#define NEWLINE 10

/*
 * Prints the number of blanks, tabs and newlines provided as input.
 */
int
main()
{
  int c, nb, nt, nn;
  c = nb = nt = nn = 0;

  while ((c = getchar()) != EOF) {
    if (c == BLANK) {
      nb++;
    } else if (c == TAB) {
      nt++;
    } else if (c == NEWLINE) {
      nn++;
    }
  }

  printf(
    "number of blanks: %d\nnumber of tabs: %d\nnumber of new lines: %d\n",
    nb,
    nt,
    nn
  );
}

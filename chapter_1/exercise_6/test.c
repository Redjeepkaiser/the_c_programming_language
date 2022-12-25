#include <stdio.h>

/*
 * Tests results of comparison with EOF.
 */
int
main()
{
  printf("%d\n", EOF != EOF);
  for (int c = 0; c < 128; c++)
    printf("%d\n", c != EOF);
}

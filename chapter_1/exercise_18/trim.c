#include <stdio.h>

#define MAX_LINE_LEN 1000

/* Gets a line from input and removes trailing whitespace. Returns len. */
int get_and_trim_line(char to[]);

/* Trims trailing whitespace and removes empty lines. */
int main()
{
  char curr_line[MAX_LINE_LEN];

  while (get_and_trim_line(curr_line))
    printf("%s", curr_line);
}

int get_and_trim_line(char to[])
{
  char c;
  int l;

  for (l = 0; l < MAX_LINE_LEN && (c = getchar()) != EOF &&
      c != '\t' && c != '\n' && c != ' '; l++)
    to[l] = c;

  if ((c == '\n' || c == '\t' || c == ' ') && l > 0)
  {
    to[l] = '\n';
    l++;
  }

  to[l] = '\0';
  return l;
}

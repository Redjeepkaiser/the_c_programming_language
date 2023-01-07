#include <stdio.h>

#define MAX_LINE_LEN 80         // Column before which we do our fold.

int read_line(char buffer[], int max_line_len);
int get_last_white_space(char buff[], int line_len);

int main() {
    char buff[MAX_LINE_LEN];
    int curr_coll = 0;
    int max_line_len = MAX_LINE_LEN;
    int line_len;

    while ((line_len = read_line(buff, max_line_len)) > 0) {
        max_line_len = MAX_LINE_LEN - curr_coll;

        if (line_len < max_line_len || buff[max_line_len - 1] == '\n') {
            printf("%s", buff);
        } else {
            int m = get_last_white_space(buff, line_len);

            if (m == -1) {
                printf("%s\n", buff);
                curr_coll = 0;
            } else {
                for (int i = 0; i < m; i++)
                    putchar(buff[i]);

                putchar('\n');

                for (int i = m+1; i < max_line_len; i++)
                    putchar(buff[i]);

                curr_coll = max_line_len - m - 1;
            }
        }
    }
}

int read_line(char buffer[], int max_line_len) {
    int c, i;

    for (i = 0; i < max_line_len && (c = getchar()) != EOF && c != '\n'; i++)
        buffer[i] = c;

    if (c == '\n')
    {
        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';

    return i;
}


int get_last_white_space(char buff[], int line_len) {
    int i;

    for (i = line_len; i >= 0; i--) {
        if (buff[i] == ' ' || buff[i] == '\t')
            return i;
    }

    return i;
}

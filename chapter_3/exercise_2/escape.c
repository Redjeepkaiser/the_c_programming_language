#include <stdio.h>
#define MAX_LEN 1000


/* Escapes tabs and newlines while copying the contents of string s to t. */
int escape(char* s, char* t);

/* Unescapes tabs and newlines while copying the contents of string s to t. */
int unescape(char* s, char* t);

/* First applies the escape function on a string and the the unescape function. */
int main() {
    char* s = "asd\nfasd\tfasdf";
    printf("original string: %s\n", s);
    char t[MAX_LEN];
    char k[MAX_LEN];

    if (!escape(s, t)) {
        printf("Failed\n");
        return 1;
    }

    printf("escaped string: %s\n", t);

    if (!unescape(t, k)) {
        printf("Failed\n");
        return 1;
    }

    printf("unecsaped string: %s\n", k);
 
    return 0;
}

int escape(char* s, char* t) {
    while (*s) {
        switch (*s) {
            case '\n':
                *t++ = '\\';
                *t = 'n';
                 break;
            case '\t':
                *t++ = '\\';
                *t = 't';
                break;
            default:
                *t = *s;
                break;
        }

        t++;
        s++;
    }

    *t = '\0';
    return 1;
}

int unescape(char* s, char* t) {
    while (*s && *(s+1)) {
        switch (*s) {
            case '\\':
                if (*(s + 1) == 'n') {
                    s++;
                    *t = '\n';
                } else if (*(s + 1) == 't') {
                    s++;
                    *t = '\t';
                }
                break;
            default:
                *t = *s;
                break;
        }


        t++;
        s++;
    }

    *t = '\0';
    return 1;
}

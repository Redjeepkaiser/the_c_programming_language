#include<stdio.h>
#define BUFF_SIZE 1000

/*
 * Converts short hand notation in s1 to the full version in s2
 *
 * Examples:
 *    a-z -> abc..xyz
 *    a-b-c -> abc
 *    a-z0-9 -> abc..xyz012..89
 */
int expand(char *s1, char *s2);

int main() {
    char *s = "thisisa-b-ztest0-9";
    char t[BUFF_SIZE];

    if (!expand(s, t)) {
        printf("Failed\n");
        return 1;
    }

    printf("result:\n%s\n", t);

    return 0;
}

int expand(char *s1, char *s2) {
    char prev = '\0';

    while (*s1) {
        // Check if we need to expand
        if (prev && *s1 == '-' && *(s1 + 1)) {
            char start = prev + 1;
            char end = *(s1 + 1);

            for (int i = start; i <= end; i++) {
                *s2++ = i; 
            }
        
            s1++;
        } else {
            *s2 = *s1;
            s2++;
        }

        prev = *s1;
        s1++;
    }
    
    *s2 = '\0';
    return 1;
}

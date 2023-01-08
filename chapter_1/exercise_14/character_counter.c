#include <stdio.h>

#define HIST_SIZE 100
#define NUM_CHARS 128

/*
 * Prints a horizontal histogram of the word counts.
 */
void print_vertical_hist(int *word_count)
{
    int num_chars = 0;

    for (int i = 0; i < NUM_CHARS; i++)
    {
        num_chars += word_count[i];
    }

    int largest_bar_size = 0;
    for (int i = 0; i <= NUM_CHARS; i++)
    {
        int bar_size = ((float)word_count[i] / (float)num_chars) * HIST_SIZE;
        word_count[i] = bar_size;

        if (bar_size > largest_bar_size)
        {
            largest_bar_size = bar_size;
        }
    }

    printf("\n\n");
    for (int i = largest_bar_size; i > 0; i--)
    {
        for (int j = 0; j <= NUM_CHARS; j++)
        {
            if (word_count[j] >= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    for (int j = 0; j <= NUM_CHARS; j++)
    {
        printf("-");
    }
    printf("\n");

    for (int j = 0; j <= NUM_CHARS; j++)
    {
        if (32 < j && j < 126) {
            printf("%c", j);
        } else {
            printf(" ");
        }
    }

    printf("\n\n");
}

/*
 * Prints a vertical histogram showing the number of times a character occurs in
 * the input.
 */
int main()
{
    int character_count[NUM_CHARS] = {0};

    char c;
    while ((c = getchar()) != EOF)
    {
        character_count[c] += 1;
    }
    
    print_vertical_hist(character_count);

    return 0;
}

#include <stdio.h>

#define ASCII_LOWER_S 97
#define ASCII_UPPER_S 65
#define MAX_WORD_LEN 100
#define HIST_SIZE 100

/*
 * Finds the largest index containing a non-zero value.
 */
int find_largest_word_len(int word_count[])
{
    int largest_word_len = 0;

    for (int i = MAX_WORD_LEN - 1; i > 0; i--)
    {
        if (word_count[i] > 0)
        {
            largest_word_len = i;
            break;
        }
    }

    return largest_word_len;
}

/**
 * Prints a horizontal histogram of the word counts.
 */
void print_vertical_hist(int *word_count, int *max_word_len, int *n_words)
{
    int largest_word_len = find_largest_word_len(word_count);
    int num_words = 0;

    // Skip zero length words.
    for (int i = 1; i < MAX_WORD_LEN; i++)
    {
        num_words += word_count[i];
    }

    int largest_bar_size = 0;
    for (int i = 1; i <= largest_word_len; i++)
    {
        int bar_size = ((float)word_count[i] / (float)num_words) * HIST_SIZE;
        word_count[i] = bar_size;

        if (bar_size > largest_bar_size)
        {
            largest_bar_size = bar_size;
        }
    }
    
    printf("\n");
    for (int i = largest_bar_size; i > 0; i--)
    {
        for (int j = 1; j <= largest_word_len; j++)
        {
            if (word_count[j] >= i)
            {
                printf(" # ");
            }
            else
            {
                printf("   ");
            }
        }

        printf("\n");
    }

    for (int j = 1; j <= largest_word_len; j++)
    {
        printf("---");
    }
    printf("\n");
    
    for (int j = 1; j <= largest_word_len; j++)
    {
        printf("%2.d ", j);
    }
    printf("\n");
    
    *max_word_len = largest_word_len;
    *n_words = num_words;
}

/*
 * Prints a histogram of the number of occurences of each word length.
 */
int main()
{
    int word_count[MAX_WORD_LEN] = {0};
    int curr_word_len = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (!(
                (ASCII_UPPER_S <= c && c < ASCII_UPPER_S + 28) ||
                (ASCII_LOWER_S <= c && c < ASCII_LOWER_S + 28)))
        {
            word_count[curr_word_len]++;
            curr_word_len = 0;
        }
        else
        {
            curr_word_len++;
        }
    }

    int largest_word_len;
    int num_words;

    print_vertical_hist(word_count, &largest_word_len, &num_words);

    printf("\ntotal number of words: %d\nlargest word has a length of: %d\n",
           num_words, largest_word_len);

    return 0;
}

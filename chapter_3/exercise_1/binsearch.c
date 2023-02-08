#include <stdio.h>
#include <time.h>

#define ARR_LEN 1000000

int binsearch(int x, int v[], int n);
int my_binsearch(int x, int v[], int n);

/*
 * Runs two implementations of binary search and measures their execution times.
 */
int main()
{
    int arr[ARR_LEN];

    for (int i = 0; i < ARR_LEN; i++)
        arr[i] = i;

    clock_t start, end; 
    double duration;

    start = clock();
    
    for (int i; i < 100000000; i++)
        my_binsearch(86243, arr, ARR_LEN);
    
    end = clock();
    duration = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("my bin search time: %.2f sec\n", duration);

    start = clock();
    
    for (int i; i < 100000000; i++)
        binsearch(86243, arr, ARR_LEN);
    
    end = clock();
    duration = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("bin search time: %.2f sec\n", duration);

    return 0;
}

/*
 * Binary search implementation from the book.
 */
int binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

/*
 * My binary search implementation.
 */
int my_binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high) / 2;

        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (v[high] == x)
        return high;
    if (v[low] == x)
        return low;
    return -1;
}

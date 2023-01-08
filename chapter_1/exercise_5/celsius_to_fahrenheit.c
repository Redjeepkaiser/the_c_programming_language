#include <stdio.h>

#define LOWER -40 // Lowest value in the table
#define UPPER  40 // Highest value in the table
#define STEP   10 // Step size

/*
 * Prints the Celsius-Fahrenheit table for celsius = -40, 30, ..., 40.
 */
int main()
{
  printf("Celsius\tFahrenheit\n");
  printf("-----------------------\n");

  for (float cel = UPPER; cel >= LOWER; cel -= STEP)
    printf("%-10.0f\t%-7.1f\n", cel, cel * 9.0 / 5.0 + 32.0);
}

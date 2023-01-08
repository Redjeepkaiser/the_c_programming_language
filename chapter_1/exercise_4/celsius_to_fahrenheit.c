#include <stdio.h>

/*
 * Prints the Celsius-Fahrenheit table for celsius = -40, 30, ..., 40.
 */
int main()
{
  printf("Celsius\tFahrenheit\n");
  printf("-----------------------\n");

  for (float cel = -40; cel <= 40; cel += 10)
    printf("%-10.0f\t%-7.1f\n", cel, cel * 9.0 / 5.0 + 32.0);
}


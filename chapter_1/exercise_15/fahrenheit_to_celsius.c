#include <stdio.h>

/**
 * Converts fahrenheit_to_celsius.
 */
float fahrenheit_to_celsius(float fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

/*
 * Prints the Fahrenheit-Celsius table for fahr = 0, 20, ..., 300.
 */
int main()
{
    printf("Fahrenheit\tCelsius\n");
    printf("-----------------------\n");

    for (float fahrenheit = 0; fahrenheit <= 300; fahrenheit += 20) {
        printf("%-10.0f\t%-7.1f\n", fahrenheit,
               fahrenheit_to_celsius(fahrenheit));
    }
}

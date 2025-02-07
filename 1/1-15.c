/* Rewrite the temperature conversion program to use a function for conversion. */

#include <stdio.h>

float celsius_to_fahrenheit(float celsius);

int main()
{
  float celsius;
  int lower, upper, step;

  lower = 0;   // lower limit of temperature table
  upper = 300; // upper limit
  step = 20;   // step size

  celsius = lower;
  printf("Celsius to Fahrenheit\n");
  while (celsius <= upper)
  {
    printf("%3.0f %6.1f\n", celsius, celsius_to_fahrenheit(celsius));
    celsius = celsius + step;
  }
}

float celsius_to_fahrenheit(float celsius)
{
  return (celsius * 9.0 / 5.0) + 32.0;
}
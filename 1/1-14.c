/* Write a program to print a histogram of the frequencies of different characters in its input. */

#include <stdio.h>

#define MAX_CHARACTERS 128

int main()
{
  int c, i;
  int character_frequencies[MAX_CHARACTERS];

  for (i = 0; i < MAX_CHARACTERS; ++i)
  {
    character_frequencies[i] = 0;
  }
  while ((c = getchar()) != EOF)
  {
    ++character_frequencies[c];
  }
  for (i = 0; i < MAX_CHARACTERS; ++i)
  {
    if (character_frequencies[i] > 0)
    {
      printf("%c: ", i);
      for (int j = 0; j < character_frequencies[i]; ++j)
      {
        printf("|");
      }
      printf("\n");
    }
  }
}
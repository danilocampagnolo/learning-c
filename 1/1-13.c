/* Write a program to print a histogram of the lengths of words in its input. Draw the histogram with the bars horizontal. */

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
#define MAX_WORD_LENGTH 10

int main()
{
  int c, state, word_length, i;
  int word_lengths[MAX_WORD_LENGTH];

  state = OUT;
  word_length = 0;
  for (i = 0; i < MAX_WORD_LENGTH; ++i)
  {
    word_lengths[i] = 0;
  }
  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      if (state == IN)
      {
        ++word_lengths[word_length];
        word_length = 0;
        state = OUT;
      }
    }
    else
    {
      ++word_length;
      state = IN;
    }
  }
  for (i = 0; i < MAX_WORD_LENGTH; ++i)
  {
    printf("%d: ", i);
    for (int j = 0; j < word_lengths[i]; ++j)
    {
      printf("|");
    }
    printf("\n");
  }
}
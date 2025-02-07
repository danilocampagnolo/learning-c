/* Write a ptrogram to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    printf("%s", line);
  }
}

int get_line(char s[], int lim)
{
  int c, i, j;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  for (j = i - 2; j >= 0 && (s[j] == ' ' || s[j] == '\t'); --j)
  {
    ;
  }
  if (j >= 0)
  {
    s[j + 1] = '\n';
    s[j + 2] = '\0';
    return j + 2;
  }
  else
  {
    return 0;
  }
}
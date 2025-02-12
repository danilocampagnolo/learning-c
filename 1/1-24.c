/* Write a program to check a C program for rudimentaru syntax errors like unmatched parentheses, brackets and braces. Don't forget about qoutes, both single and double, escape sequences, and comments. */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void check_syntax(char line[], int len);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    check_syntax(line, len);
  }
}

int get_line(char s[], int lim)
{
  int c, i;

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
  return i;
}

void check_syntax(char s[], int len)
{
  int i, j, k;
  int parentheses, brackets, braces;
  int single_quote, double_quote;
  int comment;

  parentheses = brackets = braces = single_quote = double_quote = comment = 0;
  for (i = 0; i < len; ++i)
  {
    if (s[i] == '(')
    {
      ++parentheses;
    }
    else if (s[i] == ')')
    {
      --parentheses;
    }
    else if (s[i] == '[')
    {
      ++brackets;
    }
    else if (s[i] == ']')
    {
      --brackets;
    }
    else if (s[i] == '{')
    {
      ++braces;
    }
    else if (s[i] == '}')
    {
      --braces;
    }
    else if (s[i] == '\'')
    {
      if (single_quote == 0)
      {
        ++single_quote;
      }
      else
      {
        --single_quote;
      }
    }
    else if (s[i] == '\"')
    {
      if (double_quote == 0)
      {
        ++double_quote;
      }
      else
      {
        --double_quote;
      }
    }
    else if (s[i] == '/' && s[i + 1] == '*')
    {
      ++comment;
    }
    else if (s[i] == '*' && s[i + 1] == '/')
    {
      --comment;
    }
  }
  if (parentheses != 0)
  {
    printf("Unmatched parentheses\n");
  }
  if (brackets != 0)
  {
    printf("Unmatched brackets\n");
  }
  if (braces != 0)
  {
    printf("Unmatched braces\n");
  }
  if (single_quote != 0)
  {
    printf("Unmatched single quote\n");
  }
  if (double_quote != 0)
  {
    printf("Unmatched double quote\n");
  }
  if (comment != 0)
  {
    printf("Unmatched comment\n");
  }
}
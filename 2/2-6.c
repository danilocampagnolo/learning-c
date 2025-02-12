/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged. */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
  unsigned x, y;
  int p, n;

  x = 0x0F;
  y = 0x0A;
  p = 4;
  n = 3;
  printf("x = %X, y = %X, p = %d, n = %d\n", x, y, p, n);
  printf("setbits(x, p, n, y) = %X\n", setbits(x, p, n, y));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  return (x & ~(~(~0 << n) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
}
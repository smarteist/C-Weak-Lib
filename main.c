#include <stdio.h>

void f ();

char x = 'a';
char y = 'b';

int main ()
{
  f (&x);
  printf ("%c %c", x, y);
  return 0;
}

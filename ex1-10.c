#include <stdio.h>

int main() {

  int c;

  char backspace = '\b';
  char tab       = '\t';
  char backslash = '\\';

  while ((c = getchar()) != EOF) {

    if (c == tab)
      printf("%ct", backslash);
    else if (c == backspace)
      printf("%cb", backslash);
    else if (c == backslash)
      printf("%c%c", backslash, backslash);
    else
      putchar(c);
  }

  return 0;
}

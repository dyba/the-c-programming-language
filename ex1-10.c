#include <stdio.h>

int main() {

  int c;

  char backspace = '\b';
  char tab       = '\t';
  char backslash = '\\';

  while ((c = getchar()) != EOF) {
  
    if (c == tab) {
      putchar(backslash); putchar('t');
    } else if (c == backspace) {
      putchar(backslash); putchar('b');
    } else if (c == backslash) {
      putchar(backslash); putchar(backslash);
    } else
      putchar(c);
  }

  return 0;
}

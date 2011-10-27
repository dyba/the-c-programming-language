#include <stdio.h>

#define IN  1
#define OUT 0

int main() {

  int c;

  int state = OUT;

  while ((c = getchar()) != EOF) {
    
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      printf("\n%c", c);
    } else
      putchar(c);
  }

  return 0;
}

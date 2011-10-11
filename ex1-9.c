#include <stdio.h>

int main() {

  int c = 0;
  int allow_spaces = 1;

  while((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c); 
      allow_spaces = 1;
    } else if (c == ' ' && allow_spaces) {
      putchar(c);
      allow_spaces = 0;
    } else {
      ;
    }
  }

  return 0;
}


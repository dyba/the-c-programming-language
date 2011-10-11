#include <stdio.h>

int main() {

  int c = 0;
  int count = 0;

  while((c = getchar()) != EOF)
    if (c == '\n' || c == '\t' || c == ' ')
      ++count;

  printf("The number of blanks, tabs, and newlines is: %d\n", count);

  return 0;
}

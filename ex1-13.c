#include <stdio.h>

#define IN  1
#define OUT 0
#define MAX_LENGTH 20

main()
{
  int c;
  int i = 0; int j;

  int state = OUT;
  int len = 0;
  int wordlens[MAX_LENGTH];
  for (i = 0; i < MAX_LENGTH; ++i) {
    wordlens[i] = 0;
  }

  while ((c = getchar()) != EOF)
    if (c == ' '  ||
        c == '\t' ||
        c == '\n' ||
        c == ','  ||
        c == ';'  ||
        c == '.'  ||
        c == '?'  ||
        c == '('  ||
        c == ')') {
      state = OUT;
      if (len != 0) {
        ++wordlens[len - 1];
        len = 0;
      }
    } else if (state == OUT) {
      state = IN;
      len++;
    } else {
      len++;
    }

  // Catch the last word
  if (len != 0)
    ++wordlens[len - 1];

  printf("\n");
  printf("---------------\n");
  printf("word lengths   \n");
  printf("---------------\n");
  for (i = 0; i < MAX_LENGTH; ++i) {
    printf("%3d: ", i + 1);
    j = 0;
    while (j < wordlens[i]) {
      printf("*");
      ++j;
    }
    printf("\n");
  }

}

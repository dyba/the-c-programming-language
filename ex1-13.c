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

    // Print a horizontal histogram
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

    printf("\n");

    int max_height = 0;

    // Determine the maximum height of the vertical chart
    for (i = 0; i <= MAX_LENGTH; i++)
	while (max_height < wordlens[i])
	    max_height++;

    // Remove this line once you fix the bug where ^D gets counted as a
    // character when it comes at the end of a word.
    printf("max_height: %d\n", max_height);

    // Print the asterisks corresponding to the frequency count
    for (i = max_height; i > 0; i--) {
	for (j = 0; j <= MAX_LENGTH; j++)
	    if (wordlens[j] >= i)
		printf("*");
	    else
		printf(" ");

	printf("\n");
    }

    // Print the ones decimal value
    for (i = 0; i <= MAX_LENGTH; i++) {
	int ones = (i + 1) % 10;
	printf("%d", ones);
    }

    printf("\n");

    // Print the tens decimal value
    for (i = 1; i <= MAX_LENGTH; i++) {

	if (i % 10 == 0)
	    printf("%d", i / 10);
	else
	    printf(" ");
    }

    printf("\n");
}

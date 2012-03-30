#include <stdio.h>

#define START_CHAR  ' '
#define END_CHAR    '~'
#define MAX_LENGTH  END_CHAR-START_CHAR+1

main()
{
    int c, i, j;
    int wordfreq[MAX_LENGTH];

    for (i = 0; i < MAX_LENGTH; ++i)
	wordfreq[i] = 0;

    while ((c = getchar()) != EOF)
	if (c >= START_CHAR && c <= END_CHAR)
	    ++wordfreq[c-START_CHAR];

    // Print a horizontal histogram
    printf("\n");
    printf("--------------------\n");
    printf("Word Frequencies	\n");
    printf("--------------------\n");

    for (i = 0; i < MAX_LENGTH; ++i) {
	printf("%3c: ", i + START_CHAR);
	for (j = 0; j < wordfreq[i]; ++j)
	    printf("*");
	printf("\n");
    }

    printf("\n");
}

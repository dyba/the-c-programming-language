#include <stdio.h>

/* The expression getchar() != EOF is either 1 or 0 */
main()
{
  printf("EOF: %d\n", getchar() != EOF);
}

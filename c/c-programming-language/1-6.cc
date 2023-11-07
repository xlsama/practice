#include <clocale>
#include <cstdio>
#include <stdio.h>

// EOF: ctrl+d

// int main() {
//   int c;

//   while ((c = getchar()) != EOF)
//     putchar(c);
// }

//  ----------------------------------------------------------------------------

// validate value of getchar() != EOF is 0 or 1
int main() {
  int c;
  c = getchar();

  printf("getchar() != EOF 的值为 %d\n", c != EOF);

  return 0;
}

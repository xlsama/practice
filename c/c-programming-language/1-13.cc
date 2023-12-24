#include <stdio.h>

int main() {
  int c, n;

  while ((c = getchar()) != EOF) {
    n++;
    putchar(c);
  }

  return 0;
}

#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    // 如果遇到空格、换行符、制表符
    if (c == ' ' || c == '\n' || c == '\t') {
      putchar('\n');
      continue;
    }

    putchar(c);
  }

  return 0;
}

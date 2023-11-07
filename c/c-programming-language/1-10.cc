#include <stdio.h>

#define ESC_CHAR '\\'

void copy_input_to_output() {
  int c;

  while ((c = getchar()) != EOF) {
    switch (c) {
    case ESC_CHAR:
      putchar(ESC_CHAR);
      putchar(ESC_CHAR);
      break;
    case '\t':
      putchar(ESC_CHAR);
      putchar('t');
      break;
    case '\b':
      putchar(ESC_CHAR);
      putchar('b');
      break;
    default:
      putchar(c);
      break;
    }
  }
}

int main() {
  copy_input_to_output();
  return 0;
}

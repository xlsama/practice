#include <cstdio>
#include <stdio.h>

// 编写一个将输入复制到输出的程序,并将其中连续的多个空格用一个空格代替
void copy_input_to_output() {
  int c;
  int temp = 0;

  while ((c = getchar()) != EOF) {
    if (c == temp && temp == ' ')
      continue;
    temp = c;
    putchar(c);
  }
}

int main() {
  copy_input_to_output();
  return 0;
}

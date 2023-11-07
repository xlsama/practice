#include <cstdio>
#include <stdio.h>

// 编写一个统计空格、制表符与换行符个数的程序
void calc_space_tab_newline() {
  int c, space, tab, newline;
  c = space = tab = newline = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      tab++;
    } else if (c == ' ') {
      space++;
    } else if (c == '\n') {
      newline++;
    }
  }

  printf("space: %d, tab: %d, newline: %d\n", space, tab, newline);
}

int main() {
  calc_space_tab_newline();
  return 0;
}

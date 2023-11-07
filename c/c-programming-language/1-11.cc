#include <stdio.h>

#define IN 1  // 在单词内
#define OUT 0 // 在单词外

int main() {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;

  while ((c = getchar()) != EOF) {
    // 字符计数器递增
    ++nc;

    if (c == '\n')
      // 换行计数器递增
      ++nl;

    // 如果遇到空格、换行符、制表符
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);

  return 0;
}

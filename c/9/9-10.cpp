#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node {
  ElemType data;
  struct node *next;
} NODE;

void print_list(NODE *L) {
  L = L->next;
  while (L != NULL) {
    printf("%3d", L->data); // 打印当前结点数据 L = L->next; // 指向下一个结点
    L = L->next;
  }
  printf("\n");
}

void insert_tail(NODE *&L) {
  L = (NODE *)malloc(sizeof(NODE));
  L->next = NULL;
  ElemType x;
  scanf("%d", &x);
  NODE *p;
  NODE *tail = L;
  while (x != 9999) {
    p = (NODE *)malloc(sizeof(NODE));
    p->data = x;
    tail->next = p;
    tail = p;
    scanf("%d", &x);
  }
  tail->next = NULL;
}

int main() {
  NODE *L = NULL;
  insert_tail(L);
  print_list(L);
  return 0;
}

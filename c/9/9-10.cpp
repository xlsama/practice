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

ElemType get_element(NODE *L, int index) {
  L = L->next;
  int i = 0;
  if (L != NULL && i < index) {
    L = L->next;
    i++;
  }
  if (L != NULL) {
    return L->data;
  } else {
    // 处理索引超出链表长度的情况，这里简单返回0
    return 0;
  }
}

// 3 4 5 6 7
// 3 99 4 5 6 7
void insert(NODE *&L, int index, ElemType element) {
  NODE *p = (NODE *)malloc(sizeof(NODE));
  NODE *s = L;
  NODE *r = L;
  p->data = element;
  int i = 0;
  while (s != NULL && i < index) {
    s = s->next;
    if (i < index - 1) {
      r = r->next;
    }
    i++;
  }
  p->next = s;
  r->next = p;
}

// 3 99  4  5  6  7
// 3 99  4  6  7
void remove(NODE *&L, int index) {
  NODE *s = L;
  NODE *r;
  int i = 1;
  while (s != NULL & i < index) {
    s = s->next;
    i++;
  }
  r = s->next;
  s->next = r->next;
  free(r);
}

int main() {
  NODE *L = NULL;
  insert_tail(L);
  // print_list(L);

  ElemType result = get_element(L, 2);
  printf("%d\n", result);
  insert(L, 2, 99);
  print_list(L);
  remove(L, 4);
  print_list(L);
  return 0;
}

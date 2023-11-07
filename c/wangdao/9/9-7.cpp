#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

void insertHeadList(LinkList &L) {
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  ElemType x;
  scanf("%d", &x);
  LinkList p;
  while (x != 9999) {
    p = (LinkList)malloc(sizeof(LNode));
    p->data = x;
    p->next = L->next;
    L->next = p;
    scanf("%d", &x);
  }
}

void insertTailList(LinkList &L) {
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  ElemType x;
  scanf("%d", &x);
  LinkList p;
  LinkList r = L;
  while (x != 9999) {
    p = (LinkList)malloc(sizeof(LNode));
    p->data = x;
    r->next = p;
    r = p;
    scanf("%d", &x);
  }
}

// 3 4 5 6 7 9999
void PrintList(LinkList L) {
  L = L->next;
  while (L != NULL) {
    printf("%d", L->data); // 打印当前结点数据
    L = L->next;           // 指向下一个结点
    if (L != NULL) {
      printf(" ");
    }
  }

  printf("\n");
}

int main() {
  LinkList L;

  insertHeadList(L);
  PrintList(L);
  insertTailList(L);
  PrintList(L);
  return 0;
}
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

void printList(LinkList L) {
  L = L->next;
  while (L != NULL) {
    printf("%3d", L->data);
    L = L->next;
  }
  printf("\n");
}

void insertListHead(LNode *&L) {
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  ElemType x;
  scanf("%d", &x);
  LNode *s; // 用来指向申请的新结点
  while (x != 9999) {
    s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    s->next = L->next;
    L->next = s;
    scanf("%d", &x);
  }
}

void insertListTail(LNode *&L) {
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  ElemType x;
  scanf("%d", &x);
  LNode *s;
  LNode *r = L;
  while (x != 9999) {
    s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;
    scanf("%d", &x);
  }
  r->next = NULL;
}

int main() {
  LinkList L;
  // insertListHead(L);
  insertListTail(L);
  printList(L);

  return 0;
}

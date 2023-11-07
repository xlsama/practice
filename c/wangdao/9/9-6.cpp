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

int findIndex(LNode *L, ElemType element) {
  L = L->next;
  int index = 0;
  while (L->data != element && L->next != NULL) {
    L = L->next;
    index++;
  }

  return index;
}

LinkList GetElem(LinkList L, int index) {
  int j = 0;
  if (index < 0) {
    return NULL;
  }
  while (L && j < index) {
    L = L->next;
    j++;
  }
  return L;
}

bool insertFrontList(LinkList L, int index, ElemType data) {
  LinkList p = GetElem(L, index - 1);
  if (p == NULL) {
    return false;
  }
  LinkList q;
  q = (LinkList)malloc(sizeof(LNode));
  q->data = data;
  q->next = p->next;
  p->next = q;
  return true;
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
  // int index = findIndex(L, 3);
  // printf("%d\n", GetElem(L, 2)->data);
  insertFrontList(L, 2, 99);
  printList(L);

  return 0;
}

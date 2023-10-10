#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node {
  ElemType data;
  struct node *next;
} NODE;

void insert_tail(NODE *&L) {
  L = (NODE *)malloc(sizeof(NODE));
  L->next = NULL;
  ElemType x;
  scanf("%d", &x);
  NODE *s;
  NODE *tail = L;
  while (x != 9999) {
    s = (NODE *)malloc(sizeof(NODE));
    s->data = x;
    tail->next = s;
    tail = s;
    scanf("%d", &x);
  }
  tail->next = NULL;
}

void print_list(NODE *L) {
  L = L->next;
  while (L != NULL) {
    printf("%3d", L->data);
    L = L->next;
  }
  printf("\n");
}

void find_middle(NODE *L, NODE *&L2) {
  L2 = (NODE *)malloc(sizeof(NODE));
  NODE *pcur;
  NODE *ppre;
  pcur = L->next;
  ppre = L->next;
  while (pcur) {
    pcur = pcur->next;
    if (pcur == NULL) {
      break;
    }
    pcur = pcur->next;
    if (pcur == NULL) {
      break;
    }
    ppre = ppre->next;
  }
  L2->next = ppre->next;
  ppre->next = NULL;
}

void reverse(NODE *L2) {
  NODE *r;
  NODE *s;
  NODE *t;
  r = L2->next;
  if (r == NULL) {
    return;
  }
  s = r->next;
  if (s == NULL) {
    return;
  }
  t = s->next;
  while (t) {
    s->next = r;
    r = s;
    s = t;
    t = t->next;
  }
  s->next = r;
  L2->next->next = NULL;
  L2->next = s;
}

int main() {
  NODE *L = NULL;

  insert_tail(L);
  print_list(L);

  NODE *L2 = NULL;
  find_middle(L, L2);
  printf("-------------------------\n");
  print_list(L);
  print_list(L2);
  printf("-------------------------\n");
  reverse(L2);
  print_list(L2);
  printf("-------------------------\n");

  return 0;
}

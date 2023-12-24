#include "01.h"
#include <cstdio>
#include <ratio>
#include <stdio.h>
#include <stdlib.h>

// 深度优先遍历
void pre_order(BiTree tree) {
  if (tree == NULL)
    return;
  printf("%c", tree->c);
  pre_order(tree->lchild);
  pre_order(tree->rchild);
}

void in_order(BiTree tree) {
  if (tree == NULL)
    return;
  in_order(tree->lchild);
  printf("%c", tree->c);
  in_order(tree->rchild);
}

void post_order(BiTree tree) {
  if (tree == NULL)
    return;
  post_order(tree->lchild);
  post_order(tree->rchild);
  printf("%c", tree->c);
}

int main() {
  BiTree pnew; // 用来指向新建的结点
  BiTree tree = NULL;
  char c;
  ptag_t phead = NULL, ptail = NULL, list_pnew = NULL, pcur = NULL;
  while (scanf("%c", &c)) {
    if (c == '\n')
      break;

    pnew = (BiTree)calloc(1, sizeof(BiTNode));
    pnew->c = c;
    list_pnew = (ptag_t)calloc(1, sizeof(tag_t)); // 给辅助队列节点申请空间
    list_pnew->p = pnew; // 辅助队列节点指向新建的结点

    if (tree == NULL) {
      tree = pnew;
      phead = list_pnew;
      ptail = list_pnew;
      pcur = list_pnew;
      continue;
    }
    ptail->pnext = list_pnew;
    ptail = list_pnew;

    if (pcur->p->lchild == NULL) {
      pcur->p->lchild = pnew;
    } else if (pcur->p->rchild == NULL) {
      pcur->p->rchild = pnew;
      pcur = pcur->pnext;
    };
  }

  printf("前序遍历: \n");
  pre_order(tree);
  printf("\n");
  printf("中序遍历: \n");
  in_order(tree);
  printf("\n");
  printf("后序遍历: \n");
  post_order(tree);
  printf("\n");

  return 0;
}

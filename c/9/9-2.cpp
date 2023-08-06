#include <cstdio>
#include <stdio.h>

#define MaxSize 50
typedef int ElementType;
typedef struct {
  ElementType data[MaxSize];
  int length;
} SqList;

bool insertList(SqList &L, int index, ElementType element) {
  // 判断 index 是否合法
  if (index < 1 || index > L.length + 1) {
    return false;
  }
  // 如果存储空间满了，不能插入
  if (L.length >= MaxSize) {
    return false;
  }
  for (int j = L.length; j >= index; j--) {
    L.data[j] = L.data[j - 1];
  }
  L.data[index - 1] = element;
  L.length++;
  return true;
}

void printList(SqList L) {
  for (int i = 0; i < L.length; i++) {
    printf("%4d", L.data[i]);
  }
  printf("\n");
}

// 顺序表的初始化及插入操作
int main() {
  SqList L;
  bool ret;
  L.data[0] = 1;
  L.data[1] = 2;
  L.data[2] = 3;
  L.length = 3;
  ret = insertList(L, 2, 60);
  if (ret) {
    printf("insert SqList success\n");
    printList(L);
  } else {
    printf("insert SqList failed\n");
  }
}

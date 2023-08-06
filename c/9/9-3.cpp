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

bool deleteItem(SqList &L, int index, ElementType &element) {
  // 判断 index 是否合法
  if (index < 1 || index > L.length) {
    return false;
  }
  element = L.data[index - 1];
  for (int j = index; j < L.length; j++) {
    L.data[j - 1] = L.data[j];
  }
  L.length--;
  return true;
}

void printList(SqList L) {
  for (int i = 0; i < L.length; i++) {
    printf("%4d", L.data[i]);
  }
  printf("\n");
}

int findItemPostion(SqList L, ElementType element) {
  for (int i = 0; i < L.length; i++) {
    if (L.data[i] == element) {
      return i + 1;
    }
  }
  return 0;
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
  printf("---------------\n");

  int delElement;
  ret = deleteItem(L, 2, delElement);
  if (ret) {
    printf("delete SqList success\n");
    printf("delete item is %d\n", delElement);
    printList(L);
  } else {
    printf("delete SqList failed\n");
  }

  int pos;
  pos = findItemPostion(L, 3);
  if (pos) {
    printf("find success, this position is %d\n", pos);
  } else {
    printf("find failed\n");
  }
}

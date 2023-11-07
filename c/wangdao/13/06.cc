#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

// 新建一个栈，读取标准输入3个整数3 4 5，入栈3 4 5，依次出栈，打印 5 4 3
// 新建循环队列（Maxsize为5），读取标准输入3 4 5 6 7
// 入队7时，队满，打印false，然后依次出队，输出 3 4 5 6

// Input
// 读取标准输入，内容依次是3 4 5，换行后，接着是3 4 5 6 7

// Output
// 如果输入是3 4 5，换行，接着是3 4 5 6 7，那么输出是

// 5 4 3

// false

// 3 4 5 6

// 注意每个数字占用两个字符的位置，5之前是有一个空格的，第三行的3之前也是有一个空格的

#define MAX_SIZE 5
#define ElemType int
typedef struct {
  ElemType data[MAX_SIZE];
  int top;
} Stack;

typedef struct {
  ElemType data[MAX_SIZE];
  int front, rear;
} Queue;

void init_stack(Stack &S) { S.top = -1; }

void push(Stack &S, ElemType value) {
  if (S.top >= MAX_SIZE) {
    return;
  }
  S.data[++S.top] = value;
}

ElemType pop(Stack &S) { return S.data[S.top--]; }

void init_queue(Queue &Q) {
  Q.front = 0;
  Q.rear = Q.front;
}

bool enqueue(Queue &Q, ElemType value) {
  if ((Q.rear + 1) % MAX_SIZE == Q.front) {
    return false;
  }
  Q.data[Q.rear] = value;
  Q.rear = (Q.rear + 1) % MAX_SIZE;
  return true;
}

ElemType dequeue(Queue &Q) {
  if (Q.front == Q.rear) {
    return NULL;
  }
  ElemType data = Q.data[Q.front];
  Q.front = (Q.front + 1) % MAX_SIZE;
  return data;
}

int main() {
  Stack S;
  init_stack(S);
  for (int i = 0; i < 3; i++) {
    int x;
    scanf("%d", &x);
    push(S, x);
  }
  for (int i = 0; i < 3; i++) {
    printf("%2d", pop(S));
  }
  printf("\n");

  Queue Q;
  init_queue(Q);
  for (int i = 0; i < 5; i++) {
    int x;
    scanf("%d", &x);
    if (!enqueue(Q, x)) {
      printf("false\n");
    };
  }
  for (int i = 0; i < 4; i++) {
    printf("%2d", dequeue(Q));
  }
  printf("\n");

  return 0;
}

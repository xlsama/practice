#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

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

void init_circle_queue(Queue &Q) {
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
  if (Q.rear == Q.front) {
    return NULL;
  }
  ElemType data = Q.data[Q.front];
  Q.front = (Q.front + 1) % MAX_SIZE;
  return data;
}

int main() {
  Stack S;
  init_stack(S);
  ElemType num;
  for (int i = 0; i < 3; i++) {
    scanf("%d", &num);
    push(S, num);
  }
  for (int i = 0; i < 3; i++) {
    printf("%2d", pop(S));
  }

  printf("\n");

  Queue Q;
  init_circle_queue(Q);
  for (int i = 0; i < 5; i++) {
    scanf("%d", &num);
    if (!enqueue(Q, num)) {
      printf("false\n");
    }
  }
  for (int i = 0; i < 4; i++) {
    printf("%2d", dequeue(Q));
  }
  printf("\n");

  return 0;
}

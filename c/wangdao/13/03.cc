#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode {
  ElemType data;
  struct LinkNode *next;
} LinkNode;
typedef struct {
  LinkNode *front, *rear;
} LinkQueue;

void init_queue(LinkQueue &Q) {
  Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
  Q.front->next = NULL;
}

bool is_empty(LinkQueue Q) { return Q.front == Q.rear; }

void enqueue(LinkQueue &Q, ElemType value) {
  LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
  p->data = value;
  p->next = NULL;
  Q.rear->next = p;
  Q.rear = p;
}

ElemType dequeue(LinkQueue &Q) {
  if (is_empty(Q)) {
    printf("Queue is empty.\n");
    return NULL;
  }
  LinkNode *p = Q.front->next;
  ElemType data = p->data;
  Q.front->next = p->next;
  if (Q.rear == p) {
    Q.rear = Q.front;
  }
  free(p);
  return data;
}

int main() {
  LinkQueue Q;
  init_queue(Q);
  enqueue(Q, 1);
  enqueue(Q, 2);
  enqueue(Q, 3);
  printf("dequeue data is: %d\n", dequeue(Q));
  printf("dequeue data is: %d\n", dequeue(Q));
  printf("dequeue data is: %d\n", dequeue(Q));
  enqueue(Q, 99);
  printf("dequeue data is: %d\n", dequeue(Q));
  return 0;
}

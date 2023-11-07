#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int
typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode;

// queue is empty: front == rear
// queue is full:  front == rear->next

void init_circle_queue(LNode *&front, LNode *&rear) {
  front = (LNode *)malloc(sizeof(LNode));
  rear = front;
  rear->next = front;
}

void enqueue(LNode *front, LNode *&rear, ElemType value) {
  if (rear->next == front) {
    LNode *pnew = (LNode *)malloc(sizeof(LNode));
    rear->data = value;
    rear->next = pnew;
    pnew->next = front;
    rear = pnew;
  } else {
    rear->data = value;
    rear = rear->next;
  }
}

void dequeue(LNode *&front, LNode *rear) {
  if (front == rear) {
    printf("queue is empty.\n");
    return;
  }
  printf("value is %d\n", front->data);
  front = front->next;
}

int main() {
  LNode *front, *rear;
  init_circle_queue(front, rear);

  enqueue(front, rear, 3);
  enqueue(front, rear, 4);

  dequeue(front, rear);
  dequeue(front, rear);
  dequeue(front, rear);

  return 0;
}

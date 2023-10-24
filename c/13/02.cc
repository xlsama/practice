#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
typedef int ElemType;
typedef struct {
  ElemType data[MAX_SIZE]; // array, stores the MAX_SIZE-1 element.
  int front, rear;         // head, tail
} Queue;

void init(Queue &Q) {
  Q.front = 0;
  Q.rear = Q.front;
}

bool is_empty(Queue Q) { return Q.rear == Q.front; }

bool enqueue(Queue &Q, ElemType value) {
  if ((Q.rear + 1) % MAX_SIZE == Q.front) {
    printf("Queue is full, enqueue failed.\n");
    return false;
  }
  Q.data[Q.rear] = value;
  Q.rear = (Q.rear + 1) % MAX_SIZE;

  return true;
}

ElemType dequeue(Queue &Q) {
  if (is_empty(Q)) {
    printf("Queue is empty.\n");
    return NULL;
  }
  ElemType data = Q.data[Q.front];
  Q.front = (Q.front + 1) % MAX_SIZE;
  return data;
}

// Circular Queue
int main() {
  Queue Q;
  init(Q);
  if (is_empty(Q)) {
    printf("Queue is empty.\n");
  } else {
    printf("Queue is not empty.\n");
  }
  bool ret;
  enqueue(Q, 1);
  enqueue(Q, 2);
  enqueue(Q, 3);
  enqueue(Q, 4);
  enqueue(Q, 5);
  ElemType data = dequeue(Q);
  printf("dequeue data: %d\n", data);
  enqueue(Q, 123);

  return 0;
}

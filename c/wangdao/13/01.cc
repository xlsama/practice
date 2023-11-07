#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50   // UPPER_SNAKE_CASE
typedef int ElemType; // UpperCamelCase
typedef struct {
  ElemType data[MAX_SIZE];
  int top;
} SqStack;

// lower_snake_case
void init_stack(SqStack &S) { S.top = -1; }

bool is_empty(SqStack S) {
  if (S.top == -1) {
    return true;
  }
  return false;
}

bool push(SqStack &S, ElemType value) {
  if (S.top >= MAX_SIZE) {
    return false;
  }
  S.data[++S.top] = value;
  return true;
}

ElemType peek(SqStack S) { return S.data[S.top]; }

ElemType pop(SqStack &S) { return S.data[S.top--]; }

int main() {
  SqStack S;
  init_stack(S);
  if (is_empty(S)) {
    printf("stack is empty.\n");
  }
  push(S, 3);
  push(S, 4);
  push(S, 5);
  printf("seek value: %d\n", peek(S));
  printf("pop value: %d\n", pop(S));
  printf("seek value: %d\n", peek(S));

  return 0;
}

#include <cstdio>
#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower = 0, upper = 100, step = 10;

  printf("摄氏度\t华氏度\n");
  printf("--------\t--------\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = (celsius * 9 / 5) + 32;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius += step;
  }
}

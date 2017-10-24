#include <stdio.h>

int main() {
  int sum = 0, sum2 = 0, i;

  for (i = 1; i <= 100; i++) {
    sum += i * i;
    sum2 += i;
  }
    
  printf("%d\n", (sum2*sum2) - sum);
  return 0;
}

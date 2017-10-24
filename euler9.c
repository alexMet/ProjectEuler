#include <stdio.h>

int main() {
  int a = 1, b, c, first, mid, last, flag = 0;

  while ((a <= 998) && (flag == 0)) {
    b = 1;
    while ((b <= 999) && (flag == 0)) {
      c = 1;
      while ((c <= 1000) && (flag == 0)) {
        if ((a*a + b*b == c*c) && (a + b + c == 1000)) {
          flag = 1; first = a; mid = b; last = c;
        }
        c++;
      }
      b++;
    }
    a++;
  }
  
  printf("%d %d %d\n", first, mid, last);
  printf("%d\n", first * mid * last);
  return 0;
}

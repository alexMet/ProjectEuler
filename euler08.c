#include <stdio.h>

int main() {
      int pinakas[1000], i, c, max, sum;
      i = 0;

      while ((c = getchar()) != EOF) {
         pinakas[i] = c - '0';
         i++;
      }
      max = pinakas[0] * pinakas[1] * pinakas[2] * pinakas[3] * pinakas[4];

      for (i=1; i<=995; i++){
          sum = pinakas[i] * pinakas[i+1] * pinakas[i+2] * pinakas[i+3] * pinakas[i+4];
          if (sum > max) max = sum;
      }

      printf("%d\n", max);
}

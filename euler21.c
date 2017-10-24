#include <stdio.h>
#include <math.h>

int sum_of_fact(int n) {
    int i, sum = 0;

    for (i = n / 2; i > 0; i--) {
        if (n % i == 0) sum += i;
        if (sum > 10000) return -1;
    }

    return sum;
}

int main(void) {
    int i, sol[10001], sum = 0;

    for (i = 1; i <= 10000; i++)
        sol[i] = sum_of_fact(i);

    for (i = 1; i <= 10000; i++) {
        if (sol[i] == -1) continue;
        if (i != sol[i] && i == sol[sol[i]]) {
            sum += sol[i];
            printf("%d:%d\n", i, sol[i]);
        }
    }

    printf("%d\n", sum);
    return 0;
}

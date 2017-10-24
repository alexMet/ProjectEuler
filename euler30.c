#include <stdio.h>
#include <math.h>

int main(void) {
    int d, i, j, k, l, m, n, o, p, q, sum = 0, ari, num, pin[10];

    for (i = 0; i < 10; i++) pin[i] = pow(i, 5);

    for (d = 0; d < 10; d++)
    for (i = 0; i < 10; i++)
    for (j = 0; j < 10; j++)
    for (k = 0; k < 10; k++)
    for (l = 0; l < 10; l++)
    for (m = 0; m < 10; m++)
    for (n = 0; n < 10; n++)
    for (o = 0; o < 10; o++)
    for (p = 0; p < 10; p++)
    for (q = 0; q < 10; q++) {
        num = q + 10*p + 100*o + 1000*n + 10000*m + 100000*l + 1000000*k + 10000000*j + 100000000*i + 1000000000*d;
        ari = pin[q] + pin[p] + pin[d] + pin[i] + pin[j] + pin[k] + pin[l] + pin[m] + pin[n] + pin[o];
        if (num == ari) sum += num;
    }

    printf("%d\n", sum - 1);
    return 0;
}

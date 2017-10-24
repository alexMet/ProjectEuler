#include <stdio.h>
#include <math.h>

int main(void) {
	int i, e[1001], b[1001], maxi;
    long double num[1001], max;

    for (i = 1; i <= 1000; i++) {
        scanf("%d,%d", &b[i], &e[i]);
        num[i] = e[i] * log10l(b[i]);
    }

    maxi = 1;
    max = num[1];
    for (i = 2; i <= 1000; i++) {
        if (max < num[i]) {
            max = num[i];
            maxi = i;
        }
    }

    printf("%d\n", maxi);
    return 0;
}

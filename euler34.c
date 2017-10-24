#include <stdio.h>

int main(void) {
    int i, p, sum = 0, cnt, digit[10];

    digit[0] = 1;
    for (i = 1; i < 10; i++)
        digit[i] = digit[i - 1] * i;

    for (i = 3; i < 100000; i++) {
        p = i;
        cnt = 0;
        
        while (p > 0) {
            cnt += digit[p % 10];
            p /= 10;
        }

        if (cnt == i) sum += i;
    }

    printf("%d\n", sum);
    return 0;
}

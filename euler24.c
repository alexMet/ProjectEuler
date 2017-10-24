#include <stdio.h>

void next(int *a, int n) {
    int j = n - 1;
    int temp;

    while (a[j] > a[j + 1]) j--;

    int k = n;
    while (a[j] > a[k]) k--;

    temp = a[j];
    a[j] = a[k];
    a[k] = temp;
    int r = n;
    int s = j+1;
    
    while (r > s) {
        temp = a[r];
        a[r] = a[s];
        a[s] = temp;
        r--;
        s++;
    }
}

int main() {
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, i;

    for (i = 2; i <= 1000000; i++) next(num, 9);
    for (i = 0; i < 10; i++) printf("%d",num[i]);

    printf("\n");
    return 0;
}

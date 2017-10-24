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
    int s = j + 1;
	
    while (r > s) {
        temp = a[r];
        a[r] = a[s];
        a[s] = temp;
        r--;
        s++;
    }
}

int main() {
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, mul, i, j;
    long double sum;
    int s[10][10];

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            s[i][j] = 0;

    i = 0;
    do {
        if ((num[1]*100+num[2]*10+num[3]) % 2 == 0 &&
            (num[2]*100+num[3]*10+num[4]) % 3 == 0 &&
            (num[3]*100+num[4]*10+num[5]) % 5 == 0 &&
            (num[4]*100+num[5]*10+num[6]) % 7 == 0 &&
            (num[5]*100+num[6]*10+num[7]) % 11 == 0 &&
            (num[6]*100+num[7]*10+num[8]) % 13 == 0 &&
            (num[7]*100+num[8]*10+num[9]) % 17 == 0) {
			
            for (j = 0; j < 10; j++)
                s[i][j] = num[j];
            i++;
        }

        next(num, 9);
        mul = 1;
        sum = 0;
        for (j = 9; j >= 0; j--) {
            sum += num[j] * mul;
            mul *= 10;
        }

    } while (sum != 123456789);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}

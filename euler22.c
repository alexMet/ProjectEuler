#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char pin[6000][30];
static int sum[6000];
static int help[300];

int main(void) {
    int i, j, all, ch, length, key2;
    char key[30];

    j = 1;
    for (i = 'A'; i <= 'Z'; i++)
    help[i] = j++;

    i = j = 0;
    while (1) {
        getchar();
        sum[i] = 0;

        while ((ch = getchar()) != '\"') {
            pin[i][j++] = ch;
            sum[i] += help[ch];
        }

        pin[i++][j] = '\0';
        j = 0;
        if (getchar() == EOF) break;
    }

    length = i - 1;
    for (j = 1; j <= length; j++) {
        strcpy(key, pin[j]);
        key2 = sum[j];

        i = j - 1;
        while (i > -1 && strcmp(pin[i], key) > 0) {
            strcpy(pin[i + 1], pin[i]);
            sum[i + 1] = sum[i];
            i--;
        }
        sum[i + 1] = key2;
        strcpy(pin[i + 1], key);
    }

    all = 0;
    for (j = 0; j <= length; j++)
        all += sum[j] * (j + 1);

    printf("%d\n", all);
    return 0;
}

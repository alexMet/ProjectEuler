#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 80

int min (int a, int b) {
    return (a < b) ? a : b;
}

int main(void) {
    int i, j, a[N][N], m[N][N];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N - 1; j++) {
            scanf("%d,", &a[i][j]);
        }	
        scanf("%d", &a[i][N - 1]);
    }

    m[0][0] = a[0][0];
    for (i = 1; i < N; i++) {
        m[i][0] = a[i][0] + m[i - 1][0];
        m[0][i] = a[0][i] + m[0][i - 1];
    }
    
    for (j = 1; j < N; j++) { 
        for (i = 1; i < N; i++) {
            int c = a[i][j];
            m[i][j] = min(c + m[i][j - 1], c + m[i - 1][j]);
            //printf("m[%d][%d]=%d ", i, j, m[i][j]);
        }
        //printf("\n");
    }

    printf("%d\n", m[N-1][N-1]);
    return 0;
}

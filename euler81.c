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
        for (j = 0; j < N-1; j++) {
            m[i][j] = INT_MAX;
            scanf("%d,", &a[i][j]);
        }
        scanf("%d", &a[i][N-1]);
        m[i][N] = INT_MAX;	
    }

    m[0][0] = a[0][0];
    for (int slice = 1; slice < 2 * N - 1; ++slice) {
        int z = slice < N ? 0 : slice - N + 1;
        for (int j = z; j <= slice - z; ++j) {

            if ((slice - j) == 0)
                m[j][slice - j] = m[j-1][slice-j] + a[j][slice-j];
            else if (j == 0)
                m[j][slice - j] = m[j][slice-j-1] + a[j][slice-j];
            else
                m[j][slice-j] = min(m[j-1][slice-j]+a[j][slice-j], m[j][slice-j-1]+a[j][slice-j]);

            //printf("m[%d][%d]=%d ", j, slice-j, m[j][slice-j]);
        }
        //printf("\n");
    }

    printf("%d\n", m[N-1][N-1]);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 100

int max (int a, int b) {
    return (a > b) ? a : b;
}

int main(int argc, char **argv) {
    FILE *fd;
    int i, j, a[N][N], m[N][N], sol;

    fd = fopen(argv[1], "r");

    for (int slice = 0; slice < N; ++slice) {
        int z = slice < N ? 0 : slice - N + 1;
        for (int j = z; j <= slice - z; ++j)
            fscanf(fd, "%d", &a[j][slice - j]);
    }

    m[0][0] = a[0][0];
    for (int slice = 1; slice < N; ++slice) {
        int z = slice < N ? 0 : slice - N + 1;
        for (int j = z; j <= slice - z; ++j) {
            if (slice - j == 0)
                m[j][slice - j] = m[j-1][slice-j] + a[j][slice-j];
            else if (j == 0) 
                m[j][slice - j] = m[j][slice-j-1] + a[j][slice-j];
            else
                m[j][slice-j] = max(m[j-1][slice-j] + a[j][slice-j], m[j][slice-j-1] + a[j][slice-j]);
        }
    }
    
    sol = m[0][N-1];
    for (i = 1; i < N; i++) 
        if (m[i][N-i-1] > sol) 
            sol = m[i][N-i-1];
	
    printf("%d\n", sol);
    return 0;
}

#include <stdio.h>

#define N 1000000

int main(void) {
	long int i, a[N], cnt, j, max, pos;

	for (i = 0; i < N; i++) a[i] = 0;

	for (i = 2; i < N; i++) {
		j = i;
		cnt = 1;
		while (j != 1) {
			if (j % 2 == 0) j /= 2;
			else j = 3*j + 1;

			cnt++;
			if (j < N && a[j] != 0) {
			    a[i] = a[j] + cnt - 1;
					break;
			}
		}

		if (a[i] == 0) a[i] = cnt;
	}

	max = a[2];
	for (i = 3; i < N; i++)
		if (a[i] > max) {
			max = a[i];
			pos = i;
		}

	printf("%ld\n", pos);
	return 0;
}

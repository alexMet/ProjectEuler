#include <stdio.h>

int main() {
	int i;
	long double f[101];

	f[0] = f[1] = 1;

	for (i = 2; i <= 100; i++)
		f[i] = f[i-1] * i;

	int n, r, k = 0;
	for (n = 1; n <= 100; n++)
		for (r = 1; r <= n; r++)
			if (f[n]/(f[r]*(f[n-r])) > 1000000) k++;
				
	printf("%d\n", k);

	return 0;
}

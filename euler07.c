#include <stdio.h>
#include <math.h>

int prime(int n) {
	int i;

	for (i = 3; i <= sqrt(n); i++)
		if (n % i == 0) return 0;

	return 1;
}

int main(void) {
	int i = 1, n = 3;

	for (;;) {
		if (prime(n)) i++;
		if (i == 10001) break;
		n += 2;
	}

	printf("%d\n", n);
	return 0;
}

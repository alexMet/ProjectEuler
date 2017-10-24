#include <stdio.h>

#define NUM 1000000

long nums[6];

int check (void) {
	int pin[] = {0,0,0,0,0,0,0,0,0,0}, i;

	for (i = 0; i < 6; i++) {
		while (nums[i] > 0) {
			++pin[nums[i] % 10];
			nums[i] = nums[i] / 10;
		}
	}

	for (i = 0; i < 10; i++)
		if (pin[i] % 6 != 0)
			return 0;

	return 1;
}

int main() {
	long int i;

	for (i = 1; i <= NUM; i++) {
		if (i == 111111 || i == 1111111) continue;
		nums[0] = i;
		nums[1] = 2*i;
		nums[2] = 3*i;
		nums[3] = 4*i;
		nums[4] = 5*i;
		nums[5] = 6*i;
		if (check()) {
			printf("%ld\n", i);
			break;
		}
	}

	return 0;
}

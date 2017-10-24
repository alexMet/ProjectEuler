#include <stdio.h>

int palindrome(int x) {
	int pin[6], i, j, not = 0;
	i = 0;

	while ((x / 10) != 0) {
		pin[i++] = x % 10;
		x = x / 10;
	}
	pin[i] = x;

	for (j = 0; j <= i/2; j++)
		if (pin[j] != pin[i - j]) {
			not = 1;
			break;
		}

	if (not) return 0;
	
	return 1;

}		

int main(void) {

	int i, j, max, gin;
	max = -1;

	for (i = 100; i <= 999; i++)
		for (j = 100; j <= 999; j++) {
			gin = i * j;
			if ((max < gin) && palindrome(gin)) max = gin;
		}

	printf("%d\n",max);
	return 0;
}

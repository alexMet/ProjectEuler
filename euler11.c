#include <stdio.h>

int main(void) {
	int i, j, pin[20][20], max = -1, gin = 0;
	FILE *fd;

	fd = fopen("txteuler11", "r");

	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			fscanf(fd, "%d", &pin[i][j]);

	for (j = 0; j <= 19; j++)
		for (i = 0; i <= 16; i++)
			if ((gin = pin[i][j]*pin[i+1][j]*pin[i+2][j]*pin[i+3][j]) > max)
				max = gin;

	for (i = 0; i <= 19; i++)
		for (j = 0; j <= 16; j++)
			if ((gin = pin[i][j]*pin[i][j+1]*pin[i][j+2]*pin[i][j+3]) > max)
				max = gin;
	
	for (i = 0; i < 17; i++)
		for (j = 0; j < 17; j++)
			if ((gin = pin[i][j]*pin[i+1][j+1]*pin[i+2][j+2]*pin[i+3][j+3]) > max)
				max = gin;

	for (j = 0; j <= 16; j++)
		for (i = 0; i <= 16; i++)
			if ((gin = pin[i][j+3]*pin[i+1][j+2]*pin[i+2][j+1]*pin[i+3][j]) > max)
				max = gin;

	printf("%d\n", max);

	return 0;
}

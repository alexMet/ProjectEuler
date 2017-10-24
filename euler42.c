#include <stdio.h>

static char pin[6000][30];
static int sum[6000];
static int help[300];

int main() {
	int i, j, n, cnt, ch;

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

	printf("%d %s %d\n", i, pin[i - 1], sum[i - 1]);
	cnt = 0;
	for (j = 0; j < i; j++) {
		for (n = 1; ; n++) {
			if (sum[j] == (n * (n + 1)) / 2) {
				cnt++;
				break;
			}
			else if (sum[j] < (n * (n + 1)) / 2)
				break;
		}
	}

	printf("%d\n", cnt);
	return 0;
}

//even fibonacci numbers sum
#include <stdio.h>

int main(void) {
	long int help,this = 1,next = 2;
	long int sum = 0;

	do {
		if (next % 2 == 0) sum += next;
		help = next;
		next = this + next;
		this = help;
	} while (next <= 4000000);
	
	printf("%ld\n",sum);
	return 0;
}

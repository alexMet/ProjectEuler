#include <stdio.h>

int count_factors(int number) {
    int factors = 0, dvsr;
                            
    for (dvsr = 1; dvsr * dvsr < number; dvsr++) {
        if (number % dvsr != 0) continue;
        factors += 2;
    }
    if (dvsr * dvsr == number) factors++;

    return factors;
}

int main(void) {
    int num = 1, triang = 1;
 
    while (1) {
        triang += (++num);
	    if (count_factors(triang) > 500) {
        	printf("%d\n", triang);
		    break;
	    }
    }

    return 0;
}

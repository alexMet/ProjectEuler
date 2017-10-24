#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv) {
	FILE *fd;
	int i;
	long double sum = 0,a;
	
	fd = fopen(argv[1],"r");

	for (i=0; i<100; i++) 
	{
		fscanf(fd,"%llf",&a);
		sum += a;
	}
	printf("%.0llf\n", sum);
	fclose(fd);
	return 0;
}

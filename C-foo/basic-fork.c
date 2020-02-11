#include <stdio.h>
#include <unistd.h>

int main()
{
	int total_sum, a, b, c, d;
	//Resources Shared
	a = 1;
	b = 2;
	c = 3;
	d = 4;

	if(fork() == 0) {
		//Executed by child
		total_sum = a + b;
		printf("\nChild exec: a + b = %d\n", total_sum);
	} else {
		//Executed by parent
		total_sum += (c + d);
		printf("\nParent exec: c + d + (a + b) = %d\n", total_sum);
	}

	printf("\n\tTotal sum = %d\n", total_sum);
}

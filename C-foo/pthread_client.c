#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc < 2) {
		printf("Usage: %s <num>\n", argv[0]);
	}

	long long limit = atol(argv[1]);

	return 0;
}

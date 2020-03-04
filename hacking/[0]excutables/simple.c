#include <stdio.h>

/**
  * Examine compiled binaries with:
  * $objdump [-M intel] -D a.out | grep -A20 main.:
  **/

int main()
{
	printf("Hello, World!\n");

	return 0;
}

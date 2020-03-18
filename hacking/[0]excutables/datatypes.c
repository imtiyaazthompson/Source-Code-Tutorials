#include <stdio.h>

int main()
{
	printf("int has size %lu bytes\n", sizeof(int));
	printf("unsigned int has size %lu bytes\n", sizeof(unsigned int));
	printf("short int has size %lu bytes\n", sizeof(short int));
	printf("long int has size %lu bytes\n", sizeof(long int));
	printf("long long int has size %lu bytes\n", sizeof(long long int));
	printf("float has size %lu bytes\n", sizeof(float));
	printf("char has size of %lu bytes\n", sizeof(char));
	return 0;
}

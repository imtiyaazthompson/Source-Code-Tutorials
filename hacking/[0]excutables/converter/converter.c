#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "convutil.h"

//decimal reaches faster ad misses out on last bit
char* dec_to_bin(char *dec, int len) {
	char *binary_string = malloc(sizeof(char) * 64);
	int decimal = atoi(dec);
	char bit[1];
	int modulo;
	do {
		modulo = decimal % 2;
		decimal /= 2;
		if (modulo == 1) {
			bit[0] = '1';
		} else {
			bit[0] = '0';
		}
		strcat(binary_string, bit);
	} while (decimal != 1);
}

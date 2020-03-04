#include <stdio.h>
#include <stdlib.h>
#include "convutil.h"

int* str_to_int_array(char *str, int base) {
	int len = get_str_len(str);
	int *number = malloc(sizeof(int)*len);
	
	for (int i = 0; i < len; i++) {
		if (base != 3) {
			number[i] = atoi(str[i]);
		}
	}

	return number;
}

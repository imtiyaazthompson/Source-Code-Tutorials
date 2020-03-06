#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "convutil.h"
#include "convcore.h"
#include "bool.h"
#include <math.h>

void get_base(char *str) {
        printf("(D)ecimal, (H)exidecimal, (B)inary: ");
        scanf("%s", str);
}


void get_number_as_string(char *str) {
        printf("Enter a number: ");
        scanf("%s", str);
}


int get_str_len(char *str) {
        return strlen(str);
}

int get_iarr_len(int *arr) {
	return sizeof(arr)/sizeof(arr[0]);
}

char* get_reverse(char *str) {
	int len = get_str_len(str);
	int mid = len/2;
	char *ret_str = malloc(sizeof(char) * len);
	for (int i = 0; i < len; i++) {
		ret_str[i] = str[len - (i + 1)];
	}

	return ret_str;
}

char* get_str_from_int(int integer) {
	//Numbers start from 48 in ASCII
	char *integer_str = malloc(sizeof(char) * 50);
	int i = 0;
	int prev_mod = 0;
	int prev_pow = 0;
	int curr_pow = 0;
	int mod = 0;
	char digit[1];

	while (prev_mod != integer) {
		prev_pow = (int) (pow(DECA, i++));
		curr_pow = (int) (pow(DECA, i));
		mod = integer % curr_pow;
		digit[0] = DIGITS + (mod - prev_mod)/prev_pow;
		strcat(integer_str, digit);
		prev_mod = mod;
	}
	return integer_str;
}

int get_hex_code(char c) {
	return ((c % 16) + 8);
}

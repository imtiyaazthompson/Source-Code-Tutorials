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
	int i = 1;
	int m = 0;
	char c[1];
	double modulo = 0.0;
	int isFirst = TRUE;
	
	//m will only equal the entire integer when (power of 10) > integer
	while (modulo != integer) {
		modulo = pow(DECA, i);
		if (isFirst == FALSE) {
			m = modulo - m;
		} else {
			m = (integer & (int) modulo);
			isFirst = FALSE;
		}
		c[0] = DIGITS + m;
		strcat(integer_str, c);
		i++;
	}
	return integer_str;
}

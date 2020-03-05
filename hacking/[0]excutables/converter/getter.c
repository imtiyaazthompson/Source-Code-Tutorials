#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "convutil.h"

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

void get_reverse(char **str) {
	int len = get_str_len(*str);
	int mid = len/2;
	for (int i = 0; i < len; i++) {
		if ( i < mid) {
			char temp = (*str)[i];
			(*str)[i] = (*str)[len - (1 + i)];
			(*str)[len - (1 + i)] = temp;
		}
	}
}

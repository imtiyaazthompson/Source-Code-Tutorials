#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "convutil.h"
#include "convcore.h"
#include <math.h>

//decimal reaches faster ad misses out on last bit
char* dec_to_bin(char *dec, int len) {
	char *binary_string = malloc(sizeof(char) * 64);
	int decimal = atoi(dec);
	char bit[1];
	int modulo;
	do {
		modulo = decimal % 2;
		decimal /= 2;
		bit[0] = (modulo == 1) ? '1':'0';
		strcat(binary_string, bit);
	} while (decimal != 1); 
	//Decimal will always be 1 before making last bit
	//Therefore last bit will always be 1
	bit[0] = '1';
	strcat(binary_string, bit);
	//Currently ordered from LSB -> MSB
	//Reversing the string gives MSB -> LSB
	return get_reverse(binary_string);
}

char* dec_to_hex(char *dec, int len) {
	char *hex_string = malloc(sizeof(char) * 18);
	int decimal = atoi(dec);
	char word[1];
	int modulo;
	do {
		modulo = decimal % 16;
		decimal /= 16;
		switch(modulo) {
			case A:
				word[0] = 'a';
				break;
			case B:
				word[0] = 'b';
				break;
			case C:
				word[0] = 'c';
				break;
			case D:
				word[0] = 'd';
				break;
			case E:
				word[0] = 'e';
				break;
			case F: 
				word[0] = 'f';
				break;
			default:
				word[0] = (48 + modulo); //Digits start from 48 (base 10) in ASCII
				break;
		}
		strcat(hex_string, word);
	} while (decimal != 0);
	strcat(hex_string, "x0");
	return get_reverse(hex_string);
}

char* bin_to_dec(char *bin, int len) {
	char *dec_string;
	//Assume that the binary string given by the user is MSB -> LSB
	char *lsb_ordered_bin = get_reverse(bin);
	//Now instead of reverse indexing the MSB ordered binary string
	//We can index as normal from i = 0 -> len - 1
	int dec = 0;
	for (int i = 0; i < len; i++) {
		char c = lsb_ordered_bin[i];
		int p = atoi(&c);
		dec += (int) (p * pow(2.0, (double) i));
	}
	*dec_string = get_str_from_int(dec);
	return dec_string;
}

void convert(char *str, int len, char **conv_str0, char **conv_str1, int base) {
	switch(base) {
		case DEC:
			*conv_str0 = dec_to_bin(str, len);
			*conv_str1 = dec_to_hex(str, len);
			break;
		case HEX:
			break;
		case BIN:
			*conv_str0 = bin_to_dec(str, len);
			strcat(*conv_str1, "lol");
			break;
		default:
			break;
	}
}

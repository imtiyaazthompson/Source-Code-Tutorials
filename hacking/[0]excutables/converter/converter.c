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
	return get_reverse(get_str_from_int(dec));
}

char* bin_to_hex(char *bin, int len) {
	char *dec_str = bin_to_dec(bin, len);
	int dlen = get_str_len(dec_str);
	return dec_to_hex(dec_str, dlen);
}

char* hex_to_dec(char *hex, int len) {
	char *lsb_ordered_hex = get_reverse(hex);
	int dec = 0;
	for (int i = 0; i < len; i++) {
		char c = lsb_ordered_hex[i];
		int p = get_hex_code(c);
		dec += (int) (p * pow(16.0, (double) i));
	}

	return get_reverse(get_str_from_int(dec));
}

char* hex_to_bin(char *hex, int len) {
	char *dec_str = hex_to_dec(hex, len);
	int dlen = get_str_len(dec_str);
	return dec_to_bin(dec_str, dlen);
}

void convert(char *str, int len, char **conv_str0, char **conv_str1, int base) {
	switch(base) {
		case DEC:
			*conv_str0 = dec_to_bin(str, len);
			*conv_str1 = dec_to_hex(str, len);
			break;
		case HEX:
			*conv_str0 = hex_to_dec(str, len);
			*conv_str1 = hex_to_bin(str, len);
			break;
		case BIN:
			*conv_str0 = bin_to_dec(str, len);
			*conv_str1 = bin_to_hex(str, len);
			break;
		default:
			break;
	}
}

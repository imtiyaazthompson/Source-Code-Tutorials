#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "convutil.h"
#include "convcore.h"

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
	get_reverse(&binary_string);
	return binary_string;
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
	get_reverse(&hex_string);
	return hex_string;
}

char *bin_to_dec(char *bin, int len) {
	char *dec_string = malloc(sizeof(char) * 50);
	get_reverse(&bin);
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
			break;
		default:
			break;
	}
}

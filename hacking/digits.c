#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void get_base(char *str);
void get_number_as_string();
int get_str_len(char *str);
int is_valid_base(char *choice);
int is_valid_number(int base, char* num, int len);

void get_base(char *str) {
	printf("(D)ecimal, (H)exidecimal, (B)inary: ");
	scanf("%s", str);
}

void string_to_lower(char *str, int len) {
	for (int i = 0; i < len; i++) {
		str[i] = tolower(str[i]);
	}
}

void get_number_as_string(char *str) {
	printf("Enter a number: ");
	scanf("%s", str);
}

int get_str_len(char *str) {
	return strlen(str);
}

int is_valid_base(char *str) {
	if (strcmp(str,"d") == 0 || strcmp(str,"decimal") == 0){
		return 1;
	} else if (strcmp(str,"h") == 0 || strcmp(str,"hex") == 0) {
		return 2;
	} else if (strcmp(str,"b") == 0 || strcmp(str,"bin") == 0) {
		return 3;
	} else {
		return 0;
	}
}

int is_valid_number(int base, char* num, int len) {
	int i;
	if (base == 1) {
		for (i = 0; i < len; i++) {
			if (isdigit(num[i])) {
				continue;
			} else {
				return 0;
			}
		}	
	} else if (base == 2) {
		for (i = 0; i < len; i++) {
			char c = num[i];
			if (isdigit(c) || isalpha(c)) {
				c = num[i];
				if (c != 'a' || c != 'b' || c != 'c' ||
				    c != 'd' || c != 'e' || c != 'f') {
					return 0;
				} else {
					continue;
				}
			}
		}
	} else {
		for (i = 0; i < len; i++) {
			if (isdigit(num[i]) && (num[i] >= 0 && num[i] <= 1)) {
				continue;
			} else {
				return 0;
			} 
		}
	}

	return 1;
}

int main()
{
	char *str = malloc(sizeof(char)*64);
	char *base = malloc(sizeof(char)*12);
	int c, len;
	get_base(base);
	get_number_as_string(str);
	len = get_str_len(str);
	string_to_lower(base, len);
	c = is_valid_base(base);
	if (c) {
		printf("Base '%s' is valid, with ret: %d\n", base,c);
	} else {
		printf("Base '%s' is NOT valid. Terminating", base);
		return EXIT_FAILURE;
	}
	printf("Base: %s\nYou chose: %s\nOf length: %d\n", base, str, get_str_len(str));
	if (is_valid_number(c, str, len)) {
		printf("The number: %s is VALID\n", str);
	} else {
		printf("The number: %s is INVALID\n", str);
		return EXIT_FAILURE;
	}

	free(str);
	free(base);
	return 0;
}

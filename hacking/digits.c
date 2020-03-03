#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void get_base(char *str);
void get_number_as_string();
int get_str_len(char *str);
int is_valid_base(char *choice);

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
	if (strcmp(str,"d") || strcmp(str,"decimal")){
		return 1;
	} else if (strcmp(str,"h") || strcmp(str,"hex")) {
		return 2;
	} else if (strcmp(str,"b") || strcmp(str,"bin")) {
		return 3;
	} else {
		return 0;
	}
}

int main()
{
	char *str = malloc(sizeof(char)*64);
	char *base = malloc(sizeof(char)*12);
	get_base(base);
	if (is_valid_base(base)) {
		printf("Base '%s' is valid\n", base);
	} else {
		printf("Base '")
	}
	get_number_as_string(str);
	string_to_lower(base, get_str_len(str));
	printf("Base: %s\nYou chose: %s\nOf length: %d\n", base, str, get_str_len(str));

	free(str);
	free(base);
	return 0;
}

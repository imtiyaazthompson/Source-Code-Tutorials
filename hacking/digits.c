#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void get_base(char *str);
void get_number_as_string();
int get_str_len(char *str);

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

int main()
{
	char *str = malloc(sizeof(char)*64);
	char *base = malloc(sizeof(char)*12);
	get_base(base);
	get_number_as_string(str);
	string_to_lower(base, get_str_len(str));
	printf("Base: %s\nYou chose: %s\nOf length: %d\n", base, str, get_str_len(str));

	free(str);
	free(base);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "convutil.h"

int main()
{
        char *str = malloc(sizeof(char)*64);
        char *base = malloc(sizeof(char)*12);
	int *number;
        int b, len;
        get_base(base);
        get_number_as_string(str);
        len = get_str_len(str);
        string_to_lower(base, get_str_len(base));
        string_to_lower(str, len);
        b = is_valid_base(base);
        if (b) {
                printf("Base '%s' is valid, with ret: %d\n", base,b);
        } else {
                printf("Base '%s' is NOT valid. Terminating", base);
                return EXIT_FAILURE;
        }
        printf("Base: %s\nYou chose: %s\nOf length: %d\n", base, str, len);
        if (is_valid_number(b, str, len)) {
                printf("The number: %s is VALID\n", str);
        } else {
                printf("The number: %s is INVALID\n", str);
                return EXIT_FAILURE;
        }

	number = str_to_int_array(str, b);
	for (int i = 0; i < get_iarr_len(number); i++) {
		printf("%d", number[i]);
	}
	printf("\nNumber array Len: %d", get_iarr_len(number));
	printf("\n");

        free(str);
        free(base);
	free(number);
        return 0;
}

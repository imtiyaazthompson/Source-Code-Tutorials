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

	char *bin_str = dec_to_bin(str, len);
	printf("Decimal: %d, Binary: %s", atoi(str), bin_str);

        free(str);
        free(base);
	free(number);
	free(bin_str);
        return 0;
}

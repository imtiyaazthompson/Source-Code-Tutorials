#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "convutil.h"
#include "convcore.h"

void string_to_lower(char *str, int len) {
        for (int i = 0; i < len; i++) {
                str[i] = tolower(str[i]);
        }
}


int is_valid_base(char *str) {
        if (strcmp(str,"d") == 0 || strcmp(str,"decimal") == 0){
                return DEC;
        } else if (strcmp(str,"h") == 0 || strcmp(str,"hex") == 0) {
                return HEX;
        } else if (strcmp(str,"b") == 0 || strcmp(str,"bin") == 0) {
                return BIN;
        } else {
                return FAIL;
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
                        printf("c is : %c\n", c);
                        if (isalpha(c)) {
                                if (c != 'a' && c != 'b' && c != 'c' &&
                                    c != 'd' && c != 'e' && c != 'f') {
                                        return 0;
                                } else {
                                        continue;
                                }
                        } else if (isdigit(c)) {
                                continue;
                        } else {
                                return 0;
                        }
                }
        } else {
                for (i = 0; i < len; i++) {
                        int c = num[i];
                        if (isdigit(c) && (c  >= 48 && c  < 50)) {
                                continue;
                        } else {
                                return 0;
                        }
                }
        }

        return 1;
}

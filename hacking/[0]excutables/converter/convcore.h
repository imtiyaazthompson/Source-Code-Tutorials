#define A 10
#define B 11
#define C 12
#define D 13
#define E 14
#define F 15

#define DEC 1
#define HEX 2
#define BIN 3
#define FAIL 0

#define DECA 10.0

#define DIGITS 48
#define ALPHAS_L 97
#define ALPHAS_U 65


char* dec_to_bin(char *dec, int len);
char* dec_to_hex(char *dec, int len);

char* bin_to_dec(char *bin, int len);
char* bin_to_hex(char *bin, int len);

char* hex_to_dec(char *hex, int len);
char* hex_to_bin(char *hex, int len);

void convert(char *str, int len, char **conv_str0, char **conv_str1, int base);

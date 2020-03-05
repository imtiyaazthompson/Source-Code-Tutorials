#define DEC 1
#define HEX 2
#define BIN 3
#define FAIL 0

void get_base(char *str);
void get_number_as_string();
void get_reverse(char **str);
int get_str_len(char *str);
void string_to_lower(char *str, int len);

int is_valid_base(char *choice);
int is_valid_number(int base, char* num, int len);

int str_to_int_array(char *str, int base, int **number);
int get_iarr_len(int *arr);

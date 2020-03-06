void get_base(char *str);
void get_number_as_string();
char* get_reverse(char *str);
char* get_str_from_int(int integer);
int get_str_len(char *str);
void string_to_lower(char *str, int len);

int is_valid_base(char *choice);
int is_valid_number(int base, char* num, int len);

int str_to_int_array(char *str, int base, int **number);
int get_iarr_len(int *arr);

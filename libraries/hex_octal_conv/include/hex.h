#include <stdio.h>

#define BUFFER_LIMIT 1024


int HexOctalConv_hex_converted_to_number(char *value);
int HexOctalConv_octal_converted_to_number(char *value);
int HexOctalConv_hex_part_to_number(char hex_part);

char HexOctalConv_convert_hex_part(int value);

void HexOctalConv_number_converted_to_hex(char *hex_value, char *value);
void HexOctalConv_number_converted_to_octal(char *octal_value, char *value);
void HexOctalConv_itoa(int value, char *str, int base);


static long rudy_pow(long value, int power);

static int size_of_string(char *value);

static void reverse_order(char *value);

#include <stdio.h>

#define BUFFER_LIMIT 1024


char hex_value[BUFFER_LIMIT];

char *HexOctalConv_number_converted_to_hex(char *value);

int HexOctalConv_hex_part_to_number(char hex_part);

long HexOctalConv_rudy_pow(long value, int power);

int HexOctalConv_size_of_string(char *value);

char HexOctalConv_convert_hex_part(int value);

void HexOctalConv_reverse_order(char *value);

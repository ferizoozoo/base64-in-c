#include "hex.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

unsigned char convert_hex_char_to_bin(unsigned char c) {
    char result;

    if (c >= 97 && c <= 102) {
        result = c - 87;
    } else if (c >= 65 && c <= 70) {
        result = c - 55;  
    } else if (c >= 48 && c <= 57) {
        result = c - 48;  
    }

    return result;
}

unsigned char *hex_to_bytes(unsigned char *input) {
    int input_length = strlen(input);

    if (input_length % 2 == 1) {
        printf("The input length is not divisible by 2");
        exit(0);
    }

    unsigned char *output = malloc(input_length / 2 + 1);

    int output_index = 0;
    for (int i = 0; i < input_length; i += 2) {
        unsigned char c1 = convert_hex_char_to_bin(input[i]);
        unsigned char c2 = convert_hex_char_to_bin(input[i + 1]);

        output[output_index++] = (c1 << 4) | c2;
    }

    return output;
}
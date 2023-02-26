#include "base64.h"
#include <stdint.h>
#include <stdlib.h>


const char base64table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

size_t base64_encoded_size(size_t input_len) {
	return ((4 * input_len / 3) + 3) & ~3;
}

char *base64_encode(const unsigned char *input, size_t input_len) {
	size_t output_len = base64_encoded_size(input_len);
	char *result = malloc(output_len + 1);
	result[output_len] = '\0';

	if (input == NULL || input_len == 0)
		return NULL;

	size_t j = 0;
	for (size_t i = 0; i < input_len; i += 3, j += 4) {
		uint32_t vector = 0;

		vector = (vector << 8) | input[i];
		if (i + 1 < input_len)
			vector = (vector << 8) | input[i+1];
		else
			vector = vector << 8;	
		if (i + 2 < input_len)
			vector = (vector << 8) | input[i+2];
		else
			vector = vector << 8;	

		result[j] = base64table[(vector >> 18) & 0x3F];
		result[j+1] = base64table[(vector >> 12) & 0x3F];
		if (i + 1 < input_len)
			result[j+2] = base64table[(vector >> 6) & 0x3F];
		if (i + 2 < input_len)
			result[j+3] = base64table[vector & 0x3F];		
	}

	int padding_count = input_len % 3 == 1 ? 2 : input_len % 3 == 2 ? 1 : 0;

	if (padding_count == 1)
		result[output_len - 1] = '=';
	if (padding_count == 2) {
		result[output_len - 1] = '=';
		result[output_len - 2] = '=';
	}	

	return result;
}
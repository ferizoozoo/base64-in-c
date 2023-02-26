#include <stdio.h>
#include <string.h>
#include "s1/base64.h"
#include "s1/hex.h"

int main()
{
    char* input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    char *bytes_from_hex_input = hex_to_bytes(input);
    printf("%s\n", base64_encode(bytes_from_hex_input, strlen(bytes_from_hex_input)));
}
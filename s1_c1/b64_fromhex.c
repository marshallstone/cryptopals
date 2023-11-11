#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/**
 * NOTE: currently does NOT support padding, bytes must be multiple of 3
 */

static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};

char *base64_fromhex(char *hex_str, size_t len) {
    int a;
    int mask = 0xFC0000;
    int b = 0;
    char *out;

    while (b < len) {
        sscanf(hex_str + b, "%6x", &a);
        for (int i = 0; i < 4; ++i) {
            strncat(out, &encoding_table[(mask & a) >> 18], 1);
            a = a << 6;
        }
        b += 6;
    }
    return out;
}


int main() {
    char *decoded;
    char *n = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    size_t nlen = strlen(n);
    decoded = base64_fromhex(n, nlen);

    printf("b64 string: %s", decoded);
    return 0;
}

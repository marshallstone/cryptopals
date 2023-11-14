#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/* Take two strings and xor them. Returns the newly xor'ed string in hex. */
/* NOTE: Caller is responsible for free. */
char *fixed_xor(char *buf1, char *buf2) {
    unsigned char n1;
    unsigned char n2;
    size_t l;

    l = strlen(buf1);
    if (l != strlen(buf2))
    {
        printf("Error: strings not of equal length!\n");
        exit(1);
    }

    char *out = malloc(l + 1);
    size_t i = 0;
    unsigned char res;
    while (i < l)
    {
        sscanf(&buf1[i], "%1hhx", &n1);
        sscanf(&buf2[i], "%1hhx", &n2);
        res = n1 ^ n2;
        sprintf(&out[i], "%x", res);
        i++;
    }

    return out;
}


int main()
{
    char *buf1 = "1c0111001f010100061a024b53535009181c";
    char *buf2 = "686974207468652062756c6c277320657965";
    char *out = fixed_xor(buf1, buf2);
    printf("%s\n", out);
    free(out);

    return 0;
}

/*
description: Write a program to encode any given string such that it gets
        converted into an unrecognizable form. Also write a decode
        function to get back the original string. Try to make the
        encryption scheme as difficult to break as possible.
author : Dilon Brahmbhatt
Created: 20 march, 2026
Modified: 20 march, 2026
*/
#include <stdio.h>
#include <string.h>
/*
description : this is a mod_exp function which calculate the base using two values
author : Dilon Brahmbhatt
Created: 20 march, 2026
Modified: 20 march, 2026
*/
long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
/*
description : this is an encoding function which uses RSA algorithm and devide the encripted values in two bytes.
author : Dilon Btahmbhatt
Created: 20 march, 2026
Modified: 20 march, 2026
*/
void encode(char *msg, unsigned char *byte_stream, int len, int e, int n)
{
    for (int i = 0; i < len; i++)
    {
        long long enc = mod_exp((int)msg[i], e, n);
        /* Split into 2 bytes */
        byte_stream[2*i]     = (enc >> 8) & 0xFF;  // high byte
        byte_stream[2*i + 1] = enc & 0xFF;         /* low byte */
    }
}
/*
description : this is a decoding function which decription the text.
author : Dilon Brahmbhatt
Created: 20 march, 2026
Modified: 20 march, 2026
*/
void decode(unsigned char *byte_stream, char *decrypted, int len, int d, int n)
{
    for (int i = 0; i < len; i++)
    {
        long long enc = (byte_stream[2*i] << 8) | byte_stream[2*i + 1];
        decrypted[i] = (char)mod_exp(enc, d, n);
    }
    decrypted[len] = '\0';

}
/*MAIN FUNCTION*/

void encode_decode()
{
    char msg[] = "HELLO DILON";
    int len = strlen(msg);
    unsigned char byte_stream[200]; /* 2 * len */
    char decrypted[100];
    /* RSA keys*/
    int p = 61, q = 53;
    int n = p * q;               /* 3233*/
    int e = 17;
    int d = 2753;
    /* Encode*/
    encode(msg, byte_stream, len, e, n);
    printf("Original: %s\n", msg);
    /* Printable ASCII representation */
    printf("Encrypted (ASCII chars): ");
    for (int i = 0; i < 2*len; i++)
    {
        unsigned char printable = (byte_stream[i] % 95) + 32;
        printf("%c", printable);
    }
    printf("\n");
    decode(byte_stream, decrypted, len, d, n);
    printf("Decrypted: %s\n", decrypted);
}


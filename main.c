#include <stdio.h>  
#include <stdlib.h> 
#include "aes.h"

static void add_padding(unsigned char* text, unsigned char* padded_text, int size)
{
    int desiredPadding = (16 - (size % 16)) % 16;

    for (int i = 0; i < size + desiredPadding; i++)
    {
        if(i >= size)
        {
            *(padded_text + i) = 0;
        }
        else
        {
            *(padded_text + i) = *(text + i);
        }
    } 
    
}

int main(int argc, char *argv[])
{
    // the expanded keySize
    int expandedKeySize = EXP_SIZE_16;

    // the expanded key
    unsigned char expandedKey[expandedKeySize];

    // the cipher key
    unsigned char key[16] = {0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14};
    //unsigned char key[24] = {0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c};
    //unsigned char key[32] = {0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24};

    // the cipher key size
    enum keySize size = SIZE_16;

    // the plaintext
    unsigned char plaintext[TEXT_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'p', 'o'};
    unsigned char paddedtext[PADDED_TEXT_SIZE]; 
    // the ciphertext
    unsigned char ciphertext[PADDED_TEXT_SIZE];
    // the decrypted text
    unsigned char decryptedtext[PADDED_TEXT_SIZE];

    int i;

    printf("**************************************************\n");
    printf("*   Basic implementation of AES algorithm in C   *\n");
    printf("**************************************************\n");

    printf("\nCipher Key (HEX format):\n");

    for (i = 0; i < SIZE_16; i++)
    {
        // Print characters in HEX format, 16 chars per line
        printf("%2.2x%c", key[i], ((i + 1) % 16) ? ' ' : '\n');
    }

    // Test the Key Expansion
    expandKey(expandedKey, key, size, expandedKeySize);

    printf("\nExpanded Key (HEX format):\n");

    for (i = 0; i < expandedKeySize; i++)
    {
        printf("%2.2x%c", expandedKey[i], ((i + 1) % 16) ? ' ' : '\n');
    }

    printf("\nPlaintext (HEX format):\n");

    for (i = 0; i < TEXT_SIZE; i++)
    {
        printf("%2.2x%c", plaintext[i], ((i + 1) % 16) ? ' ' : '\n');
    }

    //add byte padding to the text
    add_padding(plaintext, paddedtext, TEXT_SIZE);

    printf("\n\nPadded text (HEX format):\n");

    for (i = 0; i < PADDED_TEXT_SIZE; i++)
    {
        printf("%2.2x%c", paddedtext[i], ((i + 1) % 16) ? ' ' : '\n');
    }

    // AES Encryption
    for (i = 0; i < PADDED_TEXT_SIZE; i += 16)
    {
        aes_encrypt(&paddedtext[i], &ciphertext[i], key, SIZE_16);
    }

    printf("\nCiphertext (HEX format):\n");

    for (i = 0; i < PADDED_TEXT_SIZE; i++)
    {
        printf("%2.2x%c", ciphertext[i], ((i + 1) % 16) ? ' ' : '\n');
    }

    // AES Decryption
    for (i = 0; i < PADDED_TEXT_SIZE; i += 16)
    {
        aes_decrypt(&ciphertext[i], &decryptedtext[i], key, SIZE_16);
    }

    printf("\nDecrypted text (HEX format):\n");

    for (i = 0; i < TEXT_SIZE; i++)
    {
        printf("%2.2x%c", decryptedtext[i], ((i + 1) % 16) ? ' ' : '\n');
    }

    return 0;
}

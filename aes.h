#ifndef AES_H
#define AES_H

#define TEXT_SIZE (18)
#define PADDED_TEXT_SIZE (TEXT_SIZE) + ((16 - ((TEXT_SIZE) % 16)) % 16)

enum errorCode
{
    SUCCESS = 0,
    ERROR_AES_UNKNOWN_KEYSIZE,
    ERROR_MEMORY_ALLOCATION_FAILED,
};


// Implementation: Key Expansion

enum keySize
{
    SIZE_16 = 16,
    SIZE_24 = 24,
    SIZE_32 = 32
};

enum expKeySize
{
    EXP_SIZE_16 = 176,
    EXP_SIZE_24 = 208,
    EXP_SIZE_32 = 240
};

extern void expandKey(unsigned char *expandedKey, unsigned char *key, enum keySize, unsigned char expandedKeySize);

// Implementation: AES encryption
extern char aes_encrypt(unsigned char *input, unsigned char *output, unsigned char *key, enum keySize size);
// AES Decryption
extern char aes_decrypt(unsigned char *input, unsigned char *output, unsigned char *key, enum keySize size);

#endif
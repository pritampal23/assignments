#include "header.h"

#define AES_KEY_SIZE 32  // AES-256 (32 bytes key)
#define AES_BLOCK_SIZE 16 // AES block size (128-bit)

//Using Block cipher i.e. openssl AES-CTR mode to generate random numbers 

// openssl-AES Encryption function
int encrypt(unsigned char* plaintext, int plaintext_len, unsigned char* key, unsigned char* iv, unsigned char* ciphertext) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handleErrors();

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    int len;
    int ciphertext_len;

    // Encrypt the plaintext
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    ciphertext_len = len;

    // Finalize encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}
ZZ GenRandomNum(int bitlen){
    unsigned char key[AES_KEY_SIZE];    // 256-bit key
    unsigned char iv[AES_BLOCK_SIZE];   // 128-bit IV

    size_t counter = bitlen / 128;
    // Generate random key and IV
    if (RAND_bytes(key, sizeof(key)) != 1 || RAND_bytes(iv, sizeof(iv)) != 1) {
        std::cerr << "Error generating key/IV!" << std::endl;
        return ZZ(1);
    }

    unsigned char plaintext[] = {0x00, 0x01, 0x02,0x03,0x04,0x05,0x06,0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    unsigned char ciphertext[128];  // ciphertext


    //To store big Random number
    ZZ pseudo_rand = ZZ(0);
    for (size_t i = 0; i < counter; i++)
    {
        iv[AES_BLOCK_SIZE-1] = static_cast<char>(i); 

        // Encrypt
        int ciphertext_len = encrypt(plaintext, sizeof(plaintext), key, iv, ciphertext);
        for (size_t j = 0; j < 2*AES_BLOCK_SIZE; j++)
        {
            if(j < 16)
            {
                pseudo_rand = LeftShift(pseudo_rand, 8) + ZZ(static_cast<int>(ciphertext[j]));
            }
            else
                plaintext[j-16] = ciphertext[j];
        }
        
        memset(ciphertext, 0x00, sizeof(ciphertext));
        
    }
    return pseudo_rand;
    
}
ZZ GenRandomPrime(int bitlen){
    //generate random number of given bit length
    //then primality testing if return 1 accept
    ZZ probable_prime;
    while(1){
        cout << "Random number generation starts" << endl;
        probable_prime = GenRandomNum(bitlen);
        if (PrimeTest(probable_prime) == 1){
            cout << "Random prime generated" << endl;
            break;
        }
    }
    return probable_prime;
    
}

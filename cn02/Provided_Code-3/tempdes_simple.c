#include <openssl/des.h>
#include <sys/time.h> // For time measures
#include <string.h>
#include <stdio.h>

// Encryption/Decryption switches
#define ENC 1
#define DEC 0


// Convert string to DES_cblock
void str2DES_cblock(const char *str, DES_cblock *out)
{
    // Make a char pointer and point it at the start of the array
    unsigned char *o;
    o = out[0];

    // Read the string
    int i;
    for (i = 0; i < 8; i++)
        sscanf(&(str[i*2]),"%2hhx", o++);
}

int main(int argc, char *argv[])
{
    int k;
    DES_LONG	in[2];                     //8-byte data for encryption
    char *str_key = "0123456789abcdef";    //key for encryption, represented as a string of hexadecimal characters
    DES_cblock des_key;                    //key in DES_cblock format
    DES_key_schedule key;

    str2DES_cblock(str_key, &des_key);     //Convert key in string format to key in DES_cblock format 

    if ((k = DES_set_key_checked(&des_key,&key)) != 0) //Generate the actual key from des_key for encyption
        printf("\nkey error\n");


    in[0] = 1234;                          // Data for encryption
    in[1] = 5678;                        

    printf("DES Plaintext: %u%u\n",in[0],in[1]);             // DES encryption
    DES_encrypt1(in,&key,ENC);
    printf("DES Ciphertext: %u%u\n", in[0], in[1]);

    DES_encrypt1(in,&key,DEC);                                 // DES decryption
    printf("DES Decrypted Plaintex: %u%u\n",in[0],in[1]);            

    return 0;
}

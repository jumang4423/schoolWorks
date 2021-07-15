#include <openssl/des.h>
#include <sys/time.h> // For time measures
#include <string.h>
#include <stdio.h>

// Encryption/Decryption switches
#define ENC 1
#define DEC 0

const unsigned char *read_inputtext(const char *filename)
{
    // Total number of bytes
    unsigned long fsize;

    // Result of reading the file
    size_t result;

    // Now... Open the file binary with reading capabilities
    FILE *fp = fopen(filename, "rb");

    // If it can't be open, then return an error message
    if (fp == NULL) {fputs ("File error",stderr); exit (1);}

    /* Find out the number of bytes */
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);      /* Get the size of the file */
    rewind(fp);             /* Go back to the start */

    // Allocate the buffer + 1 for termination
    unsigned char* buffer = malloc(fsize * sizeof *buffer + 1);

    // Test that everything went as we expected
    if(buffer == NULL) { fputs("Memory error!", stderr); exit(2); }

    // Read the buffer
    result = fread(buffer, 1, fsize * sizeof *buffer, fp);

    // Something went wrong when we read the file; sizes to not match
    if (result != fsize) {fputs ("Reading error", stderr); exit (3);}

    // Terminate the str
    buffer[fsize] = '\0';

    // Close the file
    fclose(fp);

    // Return the pointer to the dynamic allocated array
    return buffer;
}

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
    des_key_schedule key;
    DES_cblock iv, cbc_key;

    const char *str_iv  = "fedcba9876543210";                //Initialization vector, represeted as a string of hexadecimal digits
    const char *str_key = "40fedf386da13d57";                //Key, represeted as a string of hexadecimal digits

    /* 
       Addtional variables
    */
    
    /* 
       Read text file and print out its length (in bytes)
    */

    /*
       DES encryption and its processing time
       Use the built-in function des_cbc_encrypt() with ENC mode
    */

    /*
       DES decryption and its processing time
       Use the built-in function des_cbc_encrypt() with DEC mode
    */
      
    return 0;
}

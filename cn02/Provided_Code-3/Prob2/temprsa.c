#include <openssl/crypto.h>
#include <openssl/rand.h>
#include <openssl/rsa.h>
#include <sys/time.h> // For time measures
#include <string.h>
#include <stdio.h>

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

int main(int argc, char *argv[])
{
    RSA *key;
    unsigned char *rbuff;                  // Input of RSA encryption
    unsigned char wbuff[256];              // Output of RSA encryption
    unsigned char exbuff[256];             // Output of RSA decryption
     
    int num;
    static const char rnd_seed[] = "string to make the random number generator think it has entropy";

    /*
      Addtional variables 
    */

    /*
      Read text file and print out its length (in bytes)
    */

    memset(wbuff,0,sizeof(wbuff));
    memset(exbuff,0,sizeof(exbuff));
    RAND_seed(rnd_seed, sizeof rnd_seed);
    if( (key = RSA_generate_key(2048,3,NULL,NULL)) == NULL)
        printf("\nerror generating key\n");

    /*
      RSA encryption and its processing time.
      Use the built-in function RSA_public_encrypt()
    */
    
    /*
      RSA decryption and its processing time.
      Use the built-in function RSA_private_decrypt()
    */
    
    RSA_free(key);

    return 0;
}

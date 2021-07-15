#include <openssl/des.h>
#include <sys/time.h> // For time measures
#include <string.h>
#include <stdio.h>

// Encryption/Decryption switches
#define ENC 1
#define DEC 0

// From char to DES_LONG (be aware that c is shifted)
#define c2l(c,l)    (l =((DES_LONG)(*((c)++))), \
                     l|=((DES_LONG)(*((c)++)))<< 8L, \
                     l|=((DES_LONG)(*((c)++)))<<16L, \
                     l|=((DES_LONG)(*((c)++)))<<24L)

// From DES_LONG to char (be aware that c is shifted)
#define l2c(l,c)	(*((c)++)=(unsigned char)(((l)     )&0xff), \
                     *((c)++)=(unsigned char)(((l)>> 8L)&0xff), \
                     *((c)++)=(unsigned char)(((l)>>16L)&0xff), \
                     *((c)++)=(unsigned char)(((l)>>24L)&0xff))

void write_output(const char *filename, const unsigned char *in)
{
    // Now... Open the file binary with writing capabilities
    FILE *fp = fopen(filename, "wb");

    // If it can't be open, then return an error message
    if (fp == NULL) {fputs ("File error", stderr); exit (1);}

    // Write the in-array to specificed file-location
    fwrite(in, sizeof(unsigned char), strlen((const char *)in), fp);

    // Close the it
    fclose(fp);
}

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

void my_des_cbc_encrypt(unsigned char *input, unsigned char *output, long length, DES_key_schedule ks, DES_cblock *ivec, int env){
  /*
    Assume that the input length (in byte) is a multiple of 8
    Try to undestand the macros l2c and c2l. They are important in implementation of CBC
  */
  
  unsigned char *iv;            // Initialization vector
  long l = length;              

  DES_LONG xor0, xor1;
  DES_LONG in0, in1;
  DES_LONG data[2];
  /* 
     Addtional variables
  */

  iv = ivec[0];

  //Initialize XOR-variables
  c2l(iv, xor0); 
  c2l(iv, xor1);  
 
  //Handling 8 bytes of input data each time inside the for loop.
  for(l -=8; l >= 0; l -=8){
    /*
      Your implementation of DES in CBC mode.
      Using DES_encrypt1().
    */
  }
}

int main(int argc, char *argv[])
{
    int k;
    DES_key_schedule key;
    DES_cblock iv, cbc_key;

    /*
      Other variables
    */

    /*
      Check number of command line arguments
    */

    /*
      Check key and initialization vector validities. (comprise of Hexadicimal digits or not)
    */

    /*
      Convert key and initialization vector from string to DES_cblock
    */
    
    /*
      read_inputtext();
    */
    
    
    /*
      my_des_cbc_encrypt();
    */

    
    /*
      write_output();
    */

    //Compare the resutl with that using built-in funtion des_cbc_encrypt(). Details of des_cbc_encrypt() can be seen at http://web.mit.edu/macdev/Development/MITKerberos/MITKerberosLib/DESLib/Documentation/api.html 
    
    /*
      des_cbc_encrypt();
      
    */

    
    /*
     Print out ciphertexts from  my_des_cbc_encrypt() and  des_cbc_encrypt() to compare
    */
  
    return 0;
}

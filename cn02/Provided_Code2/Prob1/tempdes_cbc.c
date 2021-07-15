#include <openssl/des.h>
#include <sys/time.h> // For time measures
#include <string.h>

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

  DES_LONG out0 = 0, out1 = 0, in0 = 0, in1 = 0;
  DES_LONG in_B[2];
  unsigned char *iv;
  long l = length;

  iv = ivec[0];
  
  //Initalize the XOR-variables
  c2l(iv, out0);
  c2l(iv, out1);

  for(l -=8; l>=0; l -=8){

    //Conver char to long
    c2l(input, in0);
    c2l(input, in1);

    //XOR operation
    in0 ^= out0;
    in1 ^= out1;

    //Put it in the DES_LONG[2] structure
    in_B[0] = in0;
    in_B[1] = in1;

    //Do the encryption with the key
    des_encrypt1(in_B, ks, env);

    //The output is stored for chaining the blocks
    out0 = in_B[0];
    out1 = in_B[1];

    //Append to the out vector
    l2c(out0, output);
    l2c(out1, output);
  }
}

int isHexadecimal(const char *str){
  int i;
  int count = 0;
  for(i = 0; i < strlen((const char*)str); i++){
    char c = str[i];
    if((c >= '0' && c <= '9') || ( c >= 'a' && c <= 'f'))
       count++;
  }
  if(count == strlen((const char*)str))
    return 1;
  else
    return 0;
}
int main(int argc, char *argv[])
{
    int k;
    des_key_schedule key;
    DES_cblock iv, cbc_key;

    const unsigned char *buffer;  
    const unsigned char *out;
    const unsigned char *out_comp;

    const char *str_iv;
    const char *str_key;
    const char *fileIn;
    const char *fileOut;
    
    size_t bufferLength; 

    if(argc != 5){
      printf("Not enough or too many arguments!\n");
      exit(1);
    }
  
    str_iv  = argv[1];
    str_key = argv[2];
    fileIn  = argv[3];
    fileOut = argv[4];
    
    if(!isHexadecimal(str_key) || !isHexadecimal(str_iv)){
      printf("IV or Key is not in Hexadecimal format\n");
      exit(1);
    }

    str2DES_cblock(str_key, &cbc_key);
    str2DES_cblock(str_iv, &iv);


    if ((k = des_set_key_checked(&cbc_key,key)) != 0)
        printf("\nkey error\n");

    buffer = read_inputtext(fileIn);
    bufferLength = strlen((const char*)buffer);
    out          = malloc(bufferLength*sizeof(unsigned char *));
    out_comp     = malloc(bufferLength*sizeof(unsigned char *));

    
    my_des_cbc_encrypt((unsigned char*)buffer, (unsigned char*)out, bufferLength, key, &iv, ENC);
    //Write file
    write_output(fileOut, out);

    //Compare the resutl with that using buil-in funtion (des_cbc_encrypt)
    des_cbc_encrypt((unsigned char*)buffer, (unsigned char*)out_comp, bufferLength, key, &iv, ENC);
    
    printf("Cipher Text: %s\n", out);
    printf("Cipher Text (built-in): %s\n", out_comp);
  
    return 0;
}

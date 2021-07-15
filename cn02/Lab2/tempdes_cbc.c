#include <openssl/des.h>
#include <sys/time.h> // For time measures
#include <string.h>
#include <stdio.h>

// Encryption/Decryption switches
#define ENC 1
#define DEC 0

// From char to DES_LONG (be aware that c is shifted)
#define c2l(c, l) (l = ((DES_LONG)(*((c)++))),         \
                   l |= ((DES_LONG)(*((c)++))) << 8L,  \
                   l |= ((DES_LONG)(*((c)++))) << 16L, \
                   l |= ((DES_LONG)(*((c)++))) << 24L)

// From DES_LONG to char (be aware that c is shifted)
#define l2c(l, c) (*((c)++) = (unsigned char)(((l)) & 0xff),        \
                   *((c)++) = (unsigned char)(((l) >> 8L) & 0xff),  \
                   *((c)++) = (unsigned char)(((l) >> 16L) & 0xff), \
                   *((c)++) = (unsigned char)(((l) >> 24L) & 0xff))

void write_output(const char *filename, const unsigned char *in)
{
    // Now... Open the file binary with writing capabilities
    FILE *fp = fopen(filename, "wb");

    // If it can't be open, then return an error message
    if (fp == NULL)
    {
        fputs("File error", stderr);
        exit(1);
    }

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
    if (fp == NULL)
    {
        fputs("File error", stderr);
        exit(1);
    }

    /* Find out the number of bytes */
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp); /* Get the size of the file */
    rewind(fp);        /* Go back to the start */

    // Allocate the buffer + 1 for termination
    unsigned char *buffer = malloc(fsize * sizeof *buffer + 1);

    // Test that everything went as we expected
    if (buffer == NULL)
    {
        fputs("Memory error!", stderr);
        exit(2);
    }

    // Read the buffer
    result = fread(buffer, 1, fsize * sizeof *buffer, fp);

    // Something went wrong when we read the file; sizes to not match
    if (result != fsize)
    {
        fputs("Reading error", stderr);
        exit(3);
    }

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
        sscanf(&(str[i * 2]), "%2hhx", o++);
}

void my_des_cbc_encrypt(unsigned char *input, unsigned char *output, long length, DES_key_schedule ks, DES_cblock *ivec, int env)
{
    unsigned char *iv; // Initialization vector
    long l = length;

    DES_LONG xor0, xor1;
    DES_LONG in0, in1;
    DES_LONG data[2];

    iv = ivec[0];

    //Initialize XOR-variables
    c2l(iv, xor0);
    c2l(iv, xor1);

    //Handling 8 bytes of input data each time inside the for loop.
    for (l -= 8; l >= 0; l -= 8)
    {
        // convert
        c2l(input, in0);
        c2l(input, in1);

        // xor-ing
        in0 ^= xor0;
        in1 ^= xor1;

        data[0] = in0;
        data[1] = in1;

        // encrypt
        des_encrypt1(data, ks, env);

        // lets store here
        xor0 = data[0];
        xor1 = data[1];

        l2c(xor0, output);
        l2c(xor1, output);
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
    size_t buf_len;
    char *ivs;
    char *keys;
    char *in;
    char *fout;
    unsigned char *buf;
    unsigned char *out;
    unsigned char *comp;

    /*
      Check number of command line arguments
    */
    if (argc != 5)
    {
        printf("4 arguments please.\n");
        exit(1);
    }

    // use args
    ivs = argv[1];
    keys = argv[2];
    in = argv[3];
    fout = argv[4];

    /*
      Check key and initialization vector validities. (comprise of Hexadicimal digits or not)
    */
    int flag = 0;
    int cnt_keys = 0;
    int cnt_ivs = 0;
    for (int i = 0; i < strlen(keys); i++)
    {
        char c = keys[i];
        if (
            (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))
        {
            cnt_keys++;
        }
    }
    for (int i = 0; i < strlen(iv); i++)
    {
        char c = ivs[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))
        {
            cnt_ivs++;
        }
    }
    if (!(cnt_keys == strlen(keys)) || !(cnt_ivs == strlen(ivs)))
    {
        printf("iv and key must be hexadecimal.\n");
        exit(1);
    }

    /*
      Convert key and initialization vector from string to DES_cblock
    */
    str2DES_cblock(keys, &cbc_key);
    str2DES_cblock(ivs, &iv);

    /*
      read_inputtext();
    */
    buf = read_inputtext(in);
    buf_len = strlen(buf);
    out = malloc(buf_len * sizeof(unsigned char *));
    comp = malloc(buf_len * sizeof(unsigned char *));

    /*
      my_des_cbc_encrypt();
    */
    my_des_cbc_encrypt((unsigned char *)buf, (unsigned char *)out, buf_len, key, &iv, ENC);

    /*
      write_output();
    */
    write_output(fout, out);

    //Compare the resutl with that using built-in funtion des_cbc_encrypt(). Details of des_cbc_encrypt() can be seen at http://web.mit.edu/macdev/Development/MITKerberos/MITKerberosLib/DESLib/Documentation/api.html

    /*
      DES_cbc_encrypt();
    */
    des_cbc_encrypt((unsigned char *)buf, (unsigned char *)comp, buf_len, key, &iv, ENC);

    /*
     Print out ciphertexts from  my_des_cbc_encrypt() and  DES_cbc_encrypt() to compare
    */
    printf("my_des_cbc ciphertext: %s\n", out);
    printf("openssl ciphertext: %s\n", comp);

    return 0;
}

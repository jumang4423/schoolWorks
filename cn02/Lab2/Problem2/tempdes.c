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

int main(int argc, char *argv[])
{
   int k;
   des_key_schedule key;
   DES_cblock iv, cbc_key;

   const char *str_iv = "fedcba9876543210";  //Initialization vector, represeted as a string of hexadecimal digits
   const char *str_key = "40fedf386da13d57"; //Key, represeted as a string of hexadecimal digits

   /* 
       Addtional variables
    */
   FILE *fp;
   fpos_t pos;
   size_t buf_len;
   const char *ivs;
   const char *keys;
   const char *in;
   const char *fout;
   const unsigned char *buf;
   const unsigned char *out;
   const unsigned char *comp;
   const unsigned char *comp_DEC;

   struct timeval t_start, t_end;
   long elapsed;

   /* 
       Read text file and print out its length (in bytes)
    */
   fp = fopen(fileIn, "rb");

   if (fseek(fp, 0L, SEEK_END) == 0)
   {
      if (fgetpos(fp, &pos) == 0)
      {
         fclose(fp);
      }
   }

   str2DES_cblock(keys, &cbc_key);
   str2DES_cblock(ivs, &iv);

   buf = read_inputtext(in);
   buf_len = strlen((const char *)buf);
   out = malloc(buf_len * sizeof(unsigned char *));
   comp = malloc(buf_len * sizeof(unsigned char *));
   comp_DEC = malloc(buf_len * sizeof(unsigned char *));
   comp_DEC = comp;

   // 1
   gettimeofday(&t_start, 0);
   DES_cbc_encrypt((unsigned char *)buf, (unsigned char *)comp, buf_len, &key, &iv, ENC);
   gettimeofday(&t_end, 0);
   elapsed = (t_end.tv_sec - t_start.tv_sec) * 1000000 + (t_end.tv_usec - t_start.tv_usec);
   printf("encrypt: %ld us\n", elapsed);

   // 2
   gettimeofday(&t_start, 0);
   DES_cbc_encrypt((unsigned char *)comp, (unsigned char *)comp_DEC, buf_len, &key, &iv, DEC);
   gettimeofday(&t_end, 0);
   elapsed = (t_end.tv_sec - t_start.tv_sec) * 1000000 + (t_end.tv_usec - t_start.tv_usec);
   printf("decrypt: %ld us\n", elapsed);
   return 0;
}

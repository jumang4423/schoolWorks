#include <openssl/sha.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // For time measures

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

int readByte(char* fileName){

  FILE* fp;
  fpos_t pos;

  fp = fopen(fileName, "rb");
  if (fp == NULL) {
    return -1L;
  }

  if (fseek(fp, 0L, SEEK_END) == 0) {
    if (fgetpos(fp, &pos) == 0) {
      fclose(fp);

      /*      if (pos > LONG_MAX) {
      return -1L;
    }
    */
    return (long int)pos;
  }
}

fclose(fp);
return -1L;
}


int main(int argc, char *argv[])
{
  int i;
  unsigned char *rbuff;            // Input of SHA1
  unsigned char wbuff[20];         // Output of SHA1
  SHA_CTX	c;

  /*
  Additional variables
  */
  int result;
  struct timeval t_start, t_end;
  long elapsed;
  /*
  Read text file and print out its length (in bytes)
  */
  printf("File containes %d bytes\n", readByte(argv[1]));
  rbuff =  (unsigned char*)read_inputtext(argv[1]);

  memset(wbuff,0,sizeof(wbuff));

  /*
  SHA1 encryption and its processing time
  Use Sha1_Init(), Sha1_Update() and Sha1_Final()
  */
  gettimeofday(&t_start, 0);
  result = SHA1_Init(&c); /* SHA1_Init???c????????????????????????????????????. */
  /*
  if (result == 1){
  printf("SHA1_Init success!\n");
}
else{
printf("SHA1_Init error!\n");
return -1;
}
*/

result = SHA1_Update(&c, rbuff, readByte(argv[1])); /* SHA1_Update??????????????????????????????argv[1]?????????. */
/*
if (result == 1){
printf("SHA1_Update success!\n");
}
else{
printf("SHA1_Update error!\n");
return -2;
}
*/

result = SHA1_Final(wbuff, &c);
/* if (result == 1){
printf("SHA1_Final success!\n");
}
else{
printf("SHA1_Final error!\n");
return -3;
}
*/
gettimeofday(&t_end, 0);
/* SHA1?????????. */
printf("sha1 = "); /* sha1 = "?????????. */
for (i = 0; i < 20; i++){ /* SHA_DIGEST_LENGTH????????????????????????. */
  printf("%02x", wbuff[i]); /* sha1???????????????16???????????????. */
}
printf("\n"); /* ?????? */
elapsed = (t_end.tv_sec-t_start.tv_sec)*1000000 + (t_end.tv_usec - t_start.tv_usec);
printf("Encryption time: %ld us\n", elapsed );

return 0;
}

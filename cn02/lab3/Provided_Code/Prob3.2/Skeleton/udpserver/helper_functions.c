#include "helper_functions.h"

//
// Description: Read input text in the returned buffer
// Usage: datamsg = read_inputtext("test.txt");
//
unsigned char *read_inputtext(const char *filename)
{
    // Total number of bytes
    unsigned long fsize;

    // Initialize the buffer array
    unsigned char *buffer;		/* Byte-buffer */

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

    // Allocate the buffer
    buffer = (unsigned char*) malloc(sizeof(unsigned char)*fsize);

    // Test that everything went as we expected
    if(buffer == NULL) { fputs("Memory error!", stderr); exit(2); }

    // Read the buffer
    result = fread (buffer, 1, fsize, fp);

    // Something went wrong when we read the file; sizes to not match
    if (result != fsize) {fputs ("Reading error", stderr); exit (3);}

    // Close the file
    fclose(fp);

    // Return the pointer to the dynamic allocated array
    return buffer;
}

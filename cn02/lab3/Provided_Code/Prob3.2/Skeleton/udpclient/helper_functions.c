
//
// Description: To append data to an additional heap variable
// Usage: strapp(&datamsg, packet.data.data);
//
void strapp(char **origstr, const char *newstr)
{
    // Be sure that nothing is NULL
    if(origstr == NULL || newstr == NULL)
    {
        fprintf(stderr, "strapp failed: Nothing to append");
        return;
    }

    // Calculate the totallength
    const size_t totalLength = strlen(newstr) + strlen(*origstr);

    // Reallocate the memory
    char *temp = (char *) realloc((void *) *origstr, (totalLength + 1) * sizeof temp);

    // Did it work?
    if (temp == NULL)
    {
        fprintf(stderr, "realloc failed\n");
        exit(EXIT_FAILURE);
    }

    // Concatenate the newstr to the origstr string
    strcat(temp, newstr);

    // Update the pointer location
    *origstr = temp;
}

//
// Description: Print the 20 bytes of sha1-values
// Usage: print_SHA1(&sha1_hash);
//
/*
void print_SHA1(const char *sha1)
{
    int i;
    short *s;
    s = sha1;

    printf("SHA-1 digest: ");
    for(i = 0; i < 10; i++)
    {
        printf("%x", s[i]);
    }
    printf("\n");
}
*/
//
// Description: Write the char-array in to the disk
// Usage: write_output(output_file, datamsg);
//
void write_output(const char *filename, const char *in)
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

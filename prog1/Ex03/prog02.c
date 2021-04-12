    #include <stdio.h>
    #include <stdlib.h>
    #include <float.h>
    #define MAX 1000
     
    int main()
    {
      char in_filename[] = "data02.in";   
      char out_filename[] = "data02.out";
      FILE *fpin, *fpout;
     
      char c;
      double dan,maxa, mina;
      maxa =0;
      mina = (double)DBL_MAX;

      if ((fpin = fopen(in_filename, "r")) == NULL)
      { 
        printf("Failed to open: %s\n", in_filename);
        exit(1);
      }
      int n, i, stat;
      for (n=0; n<MAX ; n++)
	{
        /*
	  ba = fgetc(fpin);
	  
      dan = (double)ba;
*/

    stat = fscanf(fpin, "%lf", &dan);
    if(stat == EOF) break;
    if(dan>=maxa) maxa = dan;
    if(dan<=mina) mina = dan;
     
	}
printf("%d", n);

      if ((fpout = fopen(out_filename, "w")) == NULL)
      {
        printf("Failed to open: %s\n", out_filename);
        fclose(fpin);
        exit(2);

      }

	  fprintf(fpout, "max = %0.3lf, min = %0.3lf ", maxa, mina);      

      fclose(fpout);
      fclose(fpin);

      return 0;
    }


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 20

typedef struct{
  char  sid[8];
  char  surname[10];
  int   score[4];
  char  grade;
  double ave;
  int sum;
} Record;

char grade_char(double score)
{
    char ass;
    if(score<(double)35) ass='F';
    else if(score>=(double)35 && score<(double)50) ass='D';
    else if(score>=(double)50 && score<(double)65) ass='C';
    else if(score>=(double)65 && score<(double)80) ass='B';
    else ass='A';
    return ass;
}

int findah(char c[10], Record data)
{
  int i, dat;
  if(c[0]>=48 && c[0] <=57)
  {
      if(strcmp(c, data.sid)==0) return 1;
  }
  else
  {
    if(strcmp(c, data.surname)==0) return 1;
  }
 
  return 0;
}

//strcmp

void output(Record data)
{
    printf("%s ", data.sid);
    printf("%s ", data.surname);
    printf("%d ", data.score[0]);
    printf("%d ", data.score[1]);
    printf("%d ", data.score[2]);
    printf("%d ", data.score[3]);
    printf("%d ", data.sum);
    printf("%.1f ", data.ave);
    printf("%c ", grade_char(data.ave)); //
    printf("\n");
}

int main(int argc, char *argv[])
{
    //file detection
    if ((int)argv[1] == 0)
    {
        printf("Error!  Usage: ./a.out datafilename\n"); 
        exit(0);
    }
    Record data[N];
    FILE *fpin;
    char c;
    char inp[10];
    int i, j, k, stat, last, flag;

    if ((fpin = fopen(argv[1], "r")) == NULL)
    {
        printf("Failed to open\n");
        exit(1);
    }

  for(i=0; i<N; i++)
  {
    stat = fscanf(fpin, "%s", data[i].sid);
    if(stat == EOF) break;
    fscanf(fpin, "%s", data[i].surname);
    fscanf(fpin, "%d", &data[i].score[0]);
    fscanf(fpin, "%d", &data[i].score[1]);
    fscanf(fpin, "%d", &data[i].score[2]);
    fscanf(fpin, "%d", &data[i].score[3]);
    data[i].sum = data[i].score[0] + data[i].score[1] + data[i].score[2] + data[i].score[3];
    data[i].ave = (double)data[i].sum / (double)4;
  }
  last = i;
  for(j=0; j<i; j++)
  {
    output(data[j]);
  }

  //input
  while(1)
  {
    printf("Input a student name/ID : ");
    stat = scanf("%s", inp);
    if(stat==EOF) 
    {
      printf("\n");
      return 0;
    }
    //searching
    flag = 0;
    for(i=0; i<last; i++)
    {
      if(findah( inp, data[i])==1) 
      {
        flag = 1;
        output(data[i]);
      }
    }
    if(flag==0) printf("This student does not exist !\n");
  }
  fclose(fpin);
  return 0;
}


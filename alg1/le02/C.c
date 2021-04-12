#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N;
char swap;

void bubbleSort(char c[][3])
{
	for(int i = 0; i<=N-1; i++)
	{
		for(int j = N-1; j>=i+1; j-- )
		{
			if(c[j][1] < c[j-1][1])
			{
				//number
				swap = c[j][1];
				c[j][1] = c[j-1][1];
				c[j-1][1] = swap;
				//char
				swap = c[j][0];
				c[j][0] = c[j-1][0];
				c[j-1][0] = swap;
			}
		}
	}
}

void selectionSort(char A[][3])
{
	int mini,swap;
	for(int i=0; i<=N-1; i++)
    {
      mini = i;
      for(int j = i; j<=N-1; j++)
	{
	  if(A[j][1] < A[mini][1])
	  {
	    mini = j;
	  }
	}	
    swap=A[i][1];
	A[i][1] = A[mini][1];
	A[mini][1] = swap;
	swap=A[i][0];
	A[i][0] = A[mini][0];
	A[mini][0] = swap;
	
    }
}

int isStable(char in[][3], char out[][3])
{
	for(int i = 0; i<= N-1; i++)
	{
		for(int j = i+1; j<= N-1; j++)
		{
			for(int a = 0; a<=N-1; a++)
			{
				for(int b = a + 1; b<=N-1; b++)
				{
					if(in[i][1] == in[j][1])
					    if(in[i][1] == out[b][1] && in[i][0] == out[b][0])
					        if(in[j][1] == out[a][1] && in[j][0] == out[a][0])
					            return 0;
				}
			}
		}
	}
	return 1;
}

int main()
{
	scanf("%d", &N);
	char put[3]; //a once input to copy the input to three
	char in[N][3]; //this is coll for comparing input(un-sorted) and output(sorted)
	char inb[N][3]; 
	char ins[N][3];
	for(int i = 0; i < N; i++) 
	{
		scanf("%s", put);
		strcpy(in[i],put);
		strcpy(inb[i],put);
		strcpy(ins[i],put);
	}
	//bubbleSort thing
	bubbleSort(inb);
	for(int i = 0; i < N; i++) 
	{
		printf("%s",inb[i]);
		if(i!=N-1) printf(" ");
	}
	printf("\n");
	if(isStable(in, inb) == 1) printf("Stable\n");
	else printf("Not stable\n");
	//selectionSort thing
	selectionSort(ins);
	for(int i = 0; i < N; i++) 
	{
		printf("%s",ins[i]);
		if(i!=N-1) printf(" ");
	}
	printf("\n");
	if(isStable(in, ins) == 1) printf("Stable\n");
	else printf("Not stable\n");
	return 0;
}
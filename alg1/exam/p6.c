#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 101
#define TRUE 1
#define FALSE 0

//init
int data[MAX];
int top=0;


int isEmpty()
{
  if(top==0) return TRUE;
  return FALSE;
}

int isFull()
{
  if(top==MAX-1) return TRUE;
  return FALSE;
}

int push(int x)
{
  if(isFull()==TRUE) return FALSE;
  top++;
  data[top-1] = x;
  return TRUE;
}

int pop()
{
  if(isEmpty()==TRUE) return FALSE;
  top--;
  return data[top];
}


int main()
{
  char input[3];
  int d1,d2, stat, num;
  while(1)
  {

    stat = scanf("%s", input);
    if(stat==EOF) break;

      if(input[0]=='+')
      {
	d1 = pop();
	d2 = pop();
	push(d1+d2);
      }
      else if(input[0]=='-')
      {
	d1 = pop();
	d2 = pop();
	push(d2-d1);
      }
      else if(input[0]=='*')
      {
	d1 = pop();
	d2 = pop();
	push(d2*d1);
      }
    else
    {
      push(atoi(input));
    }	
  }

    printf("%d",data[0]);
  printf("\n");
  
  
  return 0;
}

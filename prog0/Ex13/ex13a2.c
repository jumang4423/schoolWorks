#include <stdio.h>
#include <stdlib.h>

#define STSIZE 100

void push(double);
double pop(void);

double stack[STSIZE];
int top = 0;

int main()
{
  double data, status, i;
  int now;
  while (1) 
  {
    printf("挿入:[1 データ],  取り出し:[2] >> ");
    scanf("%d", &now);
    if(now==1)
    {
      status = scanf("%lf", &data);
      push(data);
    }
    else printf("  取り出したデータ:  %.3f\n", pop() );
  }

  printf("\n");
  return 0;
}

void push(double num)
{
  if (top == STSIZE) 
  {
    printf("Stack overflow!\n");
    exit (2);
  }
  stack[top] = num;
  top++;
}

double pop(void)
{
  if (top == 0) 
  {
    printf("Stack is empty!\n");
    exit (3);
  }
  top--;
  return stack[top];
}

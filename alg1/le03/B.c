#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100005
#define TRUE 1
#define FALSE 0

typedef struct pp{
  char name[100];
  int t;
}P;

P Q[MAX+1];
P Q2[MAX+1];
//init
int head, tail, ass;

void enqueue(P x)
{
  if(head == (tail + 1) % MAX) exit(0);
  else
  {
    Q[tail] = x;
    if(tail + 1==MAX) tail = 0;
    else tail++;
  }
}

P dequeue()
{
  P x;
    x = Q[head];
    if(head + 1==MAX) head = 0;
    else head++;
    return x;
}

int main()
{
  int lsa = 0, ms = 0;

  int n, q;
  //input
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
  {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
    if(tail + 1==MAX) tail = 0;
    else tail++;
  }

  while(ass==0)
  {
    if(q - Q[head].t <0)
    {
      Q[head].t -= q;
      enqueue(dequeue());
      ms+=q;
    }
    else
    {
      ms+=Q[head].t;
      Q2[lsa] = dequeue();
      Q2[lsa].t = ms;
      lsa++;
    }
    if(tail==head) ass = 1;
  }
  //output
  for (int i = 0; i < n; i++)
  {
    printf("%s ", Q2[i].name);
    printf("%d\n", Q2[i].t);

  }

  return 0;
}


//for (int i = head; i < tail; i++) printf("%s \n", Q[i].name);
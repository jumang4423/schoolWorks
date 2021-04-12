#include<stdio.h>

int N, A[50];
int calc(int i,int M)
{
  if(M==0) return 1;
  if(i>=N) return 0;
  int answer = calc(i+1, M) || calc(i+1, M - A[i]);
  return answer;
}

int main()
{
  //input
  int M, q, ornot, get;
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &A[i]);
  scanf("%d", &q);
  for(int i=0; i<q; i++)
  {
    scanf("%d", &M);
    if((get=calc(0, M)) != 1) printf("%d\n", get);
    else printf("%d", get);
  }
  
  return 0;
}

#include<stdio.h>

int n, S[500000], call;
int l[500000/2 + 2], r[500000/2 + 2];
void merge(int n, int left,int mid,int right)
{
  int n1, n2;
  n1 = mid - left;
  n2 = right - mid;
  for(int m=0; m<n1; m++) l[m] = S[left + m];
  for(int m=0; m<n2; m++) r[m] = S[mid + m];
  l[n1] = 999999999;
  r[n2] = 999999999;
  int i = 0;
  int j = 0;
  for(int k = left; k<right; k++)
  {
    call++;
    if(l[i] <= r[j])
    {
      S[k] = l[i];
      i++;
    }
    else
    {
      S[k] = r[j];
      j++;
    }
  }
}

void ms(int n ,int left, int right)
{
  int mid;
  if(left+1 < right)
  {
    mid = (left + right) /2;
    ms(n, left, mid);
    ms(n, mid, right);
    merge(n, left, mid, right);
  }
}

int main()
{
  int right;
  int left =0;
  int mid = 0;
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &S[i]);
  right = n;
  ms(n, left, right);
  for(int i=0; i<n; i++)
  {
    printf("%d", S[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n", call);
  return 0;
}

changed
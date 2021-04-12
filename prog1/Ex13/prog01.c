#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TATE 5
#define MAX 100

int main()
{
  char *arr[TATE];
  int i;
  char buf[MAX];
  
  for(i = 0; i < TATE ; i++)
  {
    printf("Input word #%d:", i+1);
    scanf("%s", buf);
    arr[i] = malloc(sizeof(char) * strlen(buf));
    strcpy(arr[i], buf);
  }

  for(i = 0; i < TATE; i++){
    printf("Word #%d: %s\n", i+1, arr[i]);
  }
  
  for(i = 0; i < TATE; i++) free(arr[i]);

  return 0;
}

/***************************************
 * lec14-1a.c
 *
 * スタックのサンプルプログラム。
 ***************************************/
#include <stdio.h>
#include <stdlib.h>

#define STSIZE 100

void push(int);
void find(int);
int pop(void);

int stack[STSIZE];
int top = 0;

int main(){
  int data, status, i;
  int now;
  while (1) {
    printf("挿入:1, 取り出し:2, 検索:3 >> ");
    scanf("%d", &now);
    if(now==1)
    {
      status = scanf("%d", &data);
      push(data);
    }
    else if(now==2) printf("  取り出したデータ:  %d\n", pop() );
    else if(now==3)
    {
      status = scanf("%d", &data);
      find(data);
    }else break;
  }

  printf("\n");
  return 0;
}

void push(int num){
  if (top == STSIZE) {
    /* スタックがいっぱいの場合、エラー処理を行う */
    printf("Stack overflow!\n");
    exit (2);
  }
  stack[top] = num;
  top++;
}

int pop(void){
  if (top == 0) {
    /* スタックが空の場合、エラー処理を行う */
    printf("Stack is empty!\n");
    exit (3);
  }
  top--;
  return stack[top];
}

void find(int num){
  int flag, i;
  printf("  %d はスタック", num);
  for(i=0;i<top;i++)
  {
    if(stack[i]==num)
    {
      printf("[%d] ", i);
      flag =1;
    }
  }
  if(flag==0) printf("にありません\n");
  else printf("に存在します\n");
}
#include<stdio.h>
#include<stdlib.h>
#define QSIZE 5

void enqueue(double);
double dequeue(void);

double queue[QSIZE];
int head = 0;
int tail = 0;

int main()
{

    int sec, i, lo;
    double data;

    while(1)
    {
        printf("挿入:1, 取り出し:2, 表示:3, 終了:0>>");
        scanf("%d", &sec);
        if(sec==0) break;
        else if(sec==1)
        {
            scanf("%lf", &data);
            enqueue(data);
        }
        else if(sec==2)
        {
            printf("  データ: %.3f\n", dequeue());
        }
        else if(sec==3)
        {
            lo=head;
            printf("  [Queue] ");
            while(1)
           {
                if(lo==QSIZE) lo=0;
                if(lo==tail)
                {
                    printf("\n");
                    break;
                }
                printf("%.3f  ", queue[lo]);
                lo++;

           }
        }
        else break;
    }
    return 0;
}

void enqueue(double num)
{
    int next=(tail+1)%QSIZE;

    if(next == head)
    {
        printf("Queue overflow!\n");
        exit(2);
    }
    queue[tail] = num;
    tail = next;
}

double dequeue(void)
{
    double val;

    if(head == tail)
    {
        printf("Queue is empty!\n");
        exit(3);
    }
    val = queue[head];
    head = (head+1)%QSIZE;
    return val;
}
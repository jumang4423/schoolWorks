#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main()
{
    int a,b;

    int cellx, celly;
    printf("x?");
    scanf("%d", &cellx);
    printf("y?");
    scanf("%d", &celly);
    int cells[cellx+2][celly+2];
    int cells2[cellx+2][celly+2];
    int times=0; 
    //init
    srand((unsigned int)time(NULL));
    for(a=0;a<celly+2;a++)
    {
        for(b=0;b<cellx+2;b++)
        {
            cells[a][b] = rand();
            if((((cells[a][b]/1000000000)%2)==0)) cells[a][b]=0;
            else cells[a][b]=1;

            cells2[a][b]=cells[a][b];
        }
    }
    //write

    while(1)
    {   
    int a,b;
    int c;
    for(a=0;a<100;a++) printf("\n");
    printf("%d x %d cells r fighting each other\n[%d] ctrl+c to exit\n",cellx, celly, times);
    times++;

        //write
    for(a=0;a<celly;a++)
    {
        for(b=0;b<cellx;b++)
        {
            if(cells2[a+1][b+1]==0) printf("- ");
            else printf("■  ");
        }
        printf("\n");
    }

    //aroundcheck    
    for(a=0;a<celly;a++)
    {
        for(b=0;b<cellx;b++)
        {
            c=0;
            if(cells[a][b]==1) c++;
            if(cells[a+1][b]==1) c++;
            if(cells[a+2][b]==1) c++;
            if(cells[a][b+1]==1) c++;
            if(cells[a+2][b+1]==1) c++;
            if(cells[a][b+2]==1) c++;
            if(cells[a+1][b+2]==1) c++;
            if(cells[a+2][b+2]==1) c++;

            if (cells[a+1][b+1]==0)
            {
                if(c==3) cells2[a+1][b+1]=1;
                else cells2[a+1][b+1]=0;
            }
            else if (cells[a+1][b+1]==1)
            {
                if(c==2 ||c==3) cells2[a+1][b+1]=1;
                else cells2[a+1][b+1]=0;
            }

        }
    }
    //copy
    for(a=0;a<celly+2;a++)
    {
        for(b=0;b<cellx+2;b++)
        {
            cells[a][b]=cells2[a][b];
        }
    }
    printf("\n");
    usleep(50000);

    }
    return 0;
}

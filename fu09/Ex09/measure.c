#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
unsigned long getrusageval(void);
void start_timer(unsigned int *);
unsigned get_elapsed_time(unsigned int *);
unsigned int start_tm;
unsigned long getrusageval(void)
{
    struct rusage tr;
    struct timeval tv;
    getrusage(RUSAGE_SELF, &tr);
    tv = tr.ru_utime;
    return ((unsigned long)tv.tv_sec) * 1000000 + tv.tv_usec;
}
void start_timer(unsigned int *start_tm)
{
    *start_tm = (unsigned int)getrusageval();
    return;
}
unsigned int get_elapsed_time(unsigned int *start_tm)
{
    unsigned int stop_tm = (unsigned int)getrusageval();
    return (stop_tm >= *start_tm) ? (stop_tm - *start_tm) : (stop_tm);
}

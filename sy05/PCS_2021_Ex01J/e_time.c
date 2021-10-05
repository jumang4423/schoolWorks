#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

double e_time(void){
    static struct timeval now;
    gettimeofday(&now, NULL);
    return (double)(now.tv_sec + now.tv_usec / 1000000.0);
}

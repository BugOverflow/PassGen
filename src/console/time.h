#ifndef TIME_H
#define TIME_H

#include <sys/time.h>
#include <stdlib.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

#endif

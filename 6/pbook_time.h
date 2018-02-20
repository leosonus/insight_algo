#include <sys/time.h>
#include <time.h>

#define START_TIME { \
	    struct timeval _t1; \
	    if (gettimeofday(&_t1, (struct timezone *) 0) < 0) {printf("error: gettimofday\n");}

#define END_TIME \
	    struct timeval _t2; \
	    if (gettimeofday(&_t2, (struct timezone *) 0) < 0) {printf("error: gettimofday\n");} \
	    printf("%lf\n",  (double) (_t2.tv_sec - _t1.tv_sec) + (double) (_t2.tv_usec - _t1.tv_usec) / (double) 1000000);}


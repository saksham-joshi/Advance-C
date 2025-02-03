#include <time.h>
#include <stdio.h>
#include<stdlib.h>

clock_t start_time , end_time;

#define BEGIN (start_time = clock())

#define END (end_time = clock())

#define GET_ELAPSED_TIME ((double) (end_time - start_time)/ (double) CLOCKS_PER_SEC)

#define SHOW_ELAPSED_TIME printf("\n Time Taken: %lf", GET_ELAPSED_TIME);

#define RESET_TIME (end_time = start_time = 0)

int main( void )
{
    BEGIN;

    _sleep(0);

    END;

    SHOW_ELAPSED_TIME;
}
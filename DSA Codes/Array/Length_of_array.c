#include<stdio.h>

#define arLen( __array ) sizeof(__array)/sizeof(*__array)

int main( void )
{
    int ar[] = {0, 1,2,3,4,5,6,7,8,9,0};

    printf("\n Len= %llu", arLen(ar));

    return 0;
}
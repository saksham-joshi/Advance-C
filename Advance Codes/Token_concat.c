#include<stdio.h>

#define HELLOWORLD "Hello, World!"

/*
 '##' is used to concat tokens during the compile time.

 This is very useful while working on open source APIs
 and large projects. Run this code and do some move/remove
 to understand this code clearly!
*/
#define OUTPUT HELLO ## WORLD

#define CONCAT( __x, __y) __x ## __y


int main( void )
{
    printf("\n |> %s" , OUTPUT);
    
    printf("\n |> %d", CONCAT(10,20));

    printf("\n |> %f", CONCAT(10 , 12.20));

    return 0;
}
#include<stdio.h>

#define HELLOWORLD "Hello, World!"

/*
 '##' is used to concat tokens during the compile time.

 This is very useful while working on open source APIs
 and large projects. Run this code and do some move/remove
 to understand this code clearly!
*/
#define OUTPUT HELLO ## WORLD


int main( void )
{
    printf("%s" , OUTPUT);
}
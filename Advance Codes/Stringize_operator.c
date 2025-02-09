#include<stdio.h>

#define PRINT( __msg ) #__msg
/*
 #define PRINT ( __msg ) #__msg
              ^
              |
    This extra space after marco-identifier
    will create error of undeclared identifier.
    
*/

int main( void )
{
    printf ( PRINT ( Saksham Joshi is a good guy! ) );

    return 0;
}
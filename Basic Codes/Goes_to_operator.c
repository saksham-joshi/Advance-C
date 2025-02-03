#include<stdio.h>

int main ( void )
{

    int num = 10;

    while ( num --> 0) printf(" | %d ", num);

    /*
       Explaination:
            In the above line "num --> 0" the operator "-->" is not actually an operator,
            it is the combination of '--' and '>' operator.

            First the value of num is checked if it is larger than 0 or not,
            then it's value is decremented.
    */

    return 0;
}
#include <stdio.h>

inline void printTable(const long long __num , long long __length)
{
    long long output = __num;
    for(long long i = 1 ; i <= __length ; ++i)
    {
        printf("\n > %lld x %lld = %lld", __num , i, output);
        output += __num;
    }
}

int main(void)
{
    long long int num, length ;

    printf("\n ==> Enter the number and its  :- ");
    scanf_s("%lld%lld", &num , &length);

    printTable(num , length);
}
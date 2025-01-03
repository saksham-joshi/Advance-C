#include<stdio.h>
#include<time.h>

#define NEITHER_ODD_EVEN "Neither odd nor even"
#define EVEN "Even"
#define EVEN_AND_PRIME "Even and Prime"
#define ODD "Odd"
#define ODD_AND_PRIME "Odd and Prime"

/*
    As per wikipedia, a Prime number is a natural number 
    which can be either divided by 1 or itself only.

    So, negative numbers cannot be prime, they can be odd and prime
*/
inline static const char* evenOddPrime(const long long __value)
{
    if(__value == 0) return NEITHER_ODD_EVEN;
    if(__value == 2) return EVEN_AND_PRIME;
    if(__value % 2 == 0) return EVEN;
    if(__value < 0 ) return ODD;

    long long limit = __value / 2;

    for(long long i = 3; i <= limit ; i += 2 )
    {
        if(__value % i == 0) return ODD;
        limit = __value / i;
    }

    return ODD_AND_PRIME;
}

int main(){

    for(long long int i = -2000 ; i < 50000 ; ++i)
    {
        printf("\n%lld - %s", i, evenOddPrime(i));
    }

    printf("\n Time Taken = %f sec.", (float)clock() / (float)CLOCKS_PER_SEC);

    return 0;
}
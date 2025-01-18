#include<stdio.h>
#include<time.h>
#include<math.h>

#define EVEN "Even"
#define EVEN_AND_PRIME "Even and Prime"
#define ODD "Odd"
#define ODD_AND_PRIME "Odd and Prime"

long long int ITERATION_COUNT;
/*
    As per wikipedia, a Prime number is a natural number 
    which can be either divided by 1 or itself only.

    So, negative integers cannot be prime, they can be either odd or even.
*/
inline static const char* evenOddPrime(const long long __value)
{
    ITERATION_COUNT = 1;

    if(__value == 2) return EVEN_AND_PRIME;
    if(__value % 2 == 0) return EVEN;
    if(__value <= 1 ) return ODD;

    long long limit = __value / 2;

    for(long long i = 3; i <= limit ; i += 2, ++ITERATION_COUNT)
    {
        if(__value % i == 0) return ODD;
        limit = __value / i;
    }

    return ODD_AND_PRIME;
}

int main(){

    for(long long int i = 101 ; i < 120 ; ++i)
    {
        printf("\n%lld - %s", i , evenOddPrime(i));
        printf("\t- Iter= %lld", ITERATION_COUNT);
    }

    printf("\n Time Taken = %f sec.", (float)clock() / (float)CLOCKS_PER_SEC);

    return 0;
}
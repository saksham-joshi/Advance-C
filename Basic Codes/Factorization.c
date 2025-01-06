#include <stdio.h>

#define MAX_LEN_OF_FACTORIZATION 256

inline unsigned long factorize(long long __number , long long __array[MAX_LEN_OF_FACTORIZATION])
{

    unsigned long index_to_array = 0;

    long long half_limit = __number / 2;

    for(long long i = 2; i <= half_limit ; ++i)
    {
        if(__number % i == 0)
        {
            __array[index_to_array++] = i;
            __number /= i;
            half_limit = __number / 2;
            i = 1;
        }
        else if(i == half_limit)
        {
            __array[index_to_array++] = __number;
            break;
        }
    }

    return index_to_array;
    
}

int main(void)
{
    long long num;
    long long ar[MAX_LEN_OF_FACTORIZATION];

    printf("\n ==> Enter the number :- ");
    scanf_s("%lld", &num);

    unsigned long len = factorize(num , ar);

    printf("\n Factorization : ");
    for(unsigned long i = 0 ; i < len ; ++i) printf("%lld x ", ar[i]);
    puts("1");

    return 0;
}
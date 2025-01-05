#include <stdio.h>
#include <time.h>

inline int isPerfectNumber(long long __num)
{
    long long sum = 1;

    long long limit = __num / 2 ;

    for(long long i = 2 ; i <= limit ; ++i) if(__num % i == 0) sum += i;

    return __num == sum;
}

int main(void)
{
    for(long long i = 0 ; i < 100000 ; ++i ) if(isPerfectNumber(i)) printf("%lld | ", i);

    printf("\n >> Time taken = %.5f seconds" , (float) clock() / CLOCKS_PER_SEC);

    return 0;
}
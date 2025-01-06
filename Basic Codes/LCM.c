#include <stdio.h>
#include <stdarg.h>

inline long long maxValue(const long long *__array , const unsigned long long __len)
{
    const long long* end = __array + __len;
    const long long* largest = __array++;

    for(; __array < end ; ++__array) if(*__array > *largest) largest = __array;
    
    return *largest;
}

inline int isDivisibleByAll(const long long *__array , const unsigned long long __len , const long long __divided_to)
{
    const long long* end = __array + __len;

    for(; __array < end ; ++__array) {

        if(*__array == 0) continue;

        if (__divided_to % *__array != 0) return 0;
    }
    return 1;
}

inline long long leastCommonDivisor(const long long *__array , const unsigned long long __len)
{
    const long long max = maxValue(__array , __len);
    long long iterator_value = max;
    long long limit = max * max;

    for(long long i = 1 ; i <= limit ; ++i)
    {
        if(isDivisibleByAll(__array, __len , iterator_value)) return iterator_value; 

        iterator_value += max;
    }

    return 1;
}

int main(void)
{
    long long arr[] = {22, 11,33};
    printf("\n LCM = %lld.", leastCommonDivisor(arr, sizeof(arr)/sizeof(arr[0])) );

    return 0;
}
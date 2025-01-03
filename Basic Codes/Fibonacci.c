#include<stdio.h>
#include<stdlib.h>

inline static void fibonacci(long long __first , long long __second, const Uint64 __length)
{
    for(long long i = 0 ; i < __length ; i += 2)
    {
        printf("%lld | %lld | ",__first , __second);
        __first += __second;
        __second += __first;
    }
}

typedef long long Int64;
typedef unsigned long long Uint64;
typedef Int64* Int64_ptr;

inline static Int64_ptr fibonacciArray(Int64 __first , Int64 __second , const Uint64 __length)
{  
    Int64_ptr array = (Int64_ptr) calloc(__length + ((__length%2) ? 1 : 0) , sizeof(Int64));

    if(array == NULL) return NULL;

    Int64_ptr iterator = array;

    for(Uint64 i = 0 ; i < __length ; i += 2)
    {
        *iterator = __first;

        ++iterator;

        *iterator = __second;

        ++iterator;

        __first += __second;
        __second += __first; 
    }

    return array;
}

int main()
{
    Int64_ptr array = fibonacciArray(0, 1, 10);

    Int64_ptr iterator = array;

    printf("\n|| Fibonacci Series: ");
    for(int i = 0 ; i < 10 ; ++i, ++iterator){
        printf("%lld | ",*iterator);
    }

    free(array);

    return 0;
}
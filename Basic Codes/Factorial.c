#include<stdio.h>
#include<time.h>

typedef unsigned long long Uint64;

inline static Uint64 factorial(long long int __num){

    Uint64 output = 1;

    for(int i = 2 ; i <= __num ; ++i){
        output *= i;
    }

    return output;

}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsequence-point"
inline static Uint64 factorialRecursion(long long int __num)
{
    return (__num < 2) ? 1 : __num*factorialRecursion(--__num);
}
#pragma clang diagnostic pop

int main()
{
    puts("\n | Here are the factorial of numbers from -50 to 50 : ");

    // Using loop to check the speed of the function
    for(long long int i = -50 ; i <= 50 ; ++i )
    {
        printf("-> Factorial of %lld = %llu\n",i, factorialRecursion(i));
    }

    printf("\n Time Taken = %.5lf sec.", (double) clock()/ (double)CLOCKS_PER_SEC);

    return 0;
}

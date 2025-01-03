#include<stdio.h>

inline static void swap(long long * __ptr1 , long long *__ptr2)
{
    long long temp = *__ptr1;
    *__ptr1 = *__ptr2;
    *__ptr2 = temp;
}

inline static long long gcd(long long __value1, long long __value2)
{
    long long gcd = (__value1 > __value2)? __value2 : __value1;

    long long int iterator = 2;

    while(gcd != 1 && !(__value1%gcd == 0 && __value2%gcd == 0)) gcd = __value2/iterator++;
    
    return gcd;
}

// #- Don't call this function instead call hcfRecursive
inline static long long gcdRecursive(const long long __value1 , const long long __value2 , long long __gcd,  const long long __iterator)
{
    if(__gcd == 0) return 1;
    return ((__value1 % __gcd == 0 && __value2 % __gcd == 0) ? __gcd : gcdRecursive(__value1 , __value2, (__value2/__iterator), __iterator+1));
}

inline static long long hcf(long long __value1 , long long __value2)
{
    return gcd(__value1 , __value2);
}

inline static long long hcfRecursive(long long __value1, long long __value2)
{
    return gcdRecursive(__value1 , __value2, (__value1 < __value2)?__value1 : __value2, 2);
}

int main(){
    long long a , b;
    printf("\n ==> Enter two numbers :- ");
    scanf_s("%lld%lld", &a, &b);
    printf("\n || GCD of %lld & %lld = %lld.", a , b ,  hcfRecursive(a, b));
}
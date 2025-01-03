#include<stdio.h>


inline static unsigned short intDigitSum(long long __value)
{
    unsigned short sum = 0;

    if (__value < 0) __value = -__value;

    while(__value != 0){
        sum += (__value % 10);
        __value /= 10;
    }
    return sum;
}

inline static unsigned short doubleDigitSum(double __value)
{
    unsigned short sum = intDigitSum((long long)__value);

    unsigned short int count = 0;

    // storing only decimal part
    __value -= (long long) __value;

    while (count < 10 && __value != 0.0000000000) 
    {
        __value *= 10;

        sum += (unsigned short)__value;

        __value -= (long long) __value;

        ++count;
    }

    return sum;
}

int main(){

    long long int_value;
    double double_value;
    printf("\n ==> Enter an Integer & a floating value :- ");
    scanf_s("%lld%lf",&int_value, &double_value);

    printf("\n |=| Sum of digits in '%lld' = %u.\n |=| Sum of digits in '%.9g' = %u.", int_value, intDigitSum(int_value), double_value, doubleDigitSum(double_value));
}
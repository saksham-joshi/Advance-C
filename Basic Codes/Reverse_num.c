#include<stdio.h>
#include<math.h>

typedef struct{
    long long _value;
    unsigned short _digit_count;
} ValueAndDigitCount;

inline static ValueAndDigitCount intReverseWithDigitCount(long long __value)
{
    ValueAndDigitCount obj;
    obj._value = 0;
    obj._digit_count = 0;

    // if the value is zero then the digit count will also be 0
    if(__value == 0){
        obj._digit_count = 1;
        return obj;
    }

    while(__value != 0)
    {
        obj._value = (obj._value * 10) + (long long)__value%10;
        __value /= 10;
        ++obj._digit_count;
    }

    return obj;
}

inline static long long intReverse(long long __value)
{
    return intReverseWithDigitCount(__value)._value;
}

inline static double doubleReverse(double __value)
{
    ValueAndDigitCount obj = intReverseWithDigitCount((long long) __value);
    
    double rev = (double)obj._value / pow(10, (double)obj._digit_count);

    // stored only decimal part
    __value -= (long long) __value;

    unsigned short count = 0;

    while(++count < 10 && __value != (long) __value) __value *= 10;

    return (rev + (double)intReverse((long long)__value));
}

int main()
{
    double x = 12345.6789;
    long long y = 123456789;
    printf("\n =| Reverse of %lf = %lf.", x, doubleReverse(x));
    printf("\n =| Reverse of %lld = %lld.", y , intReverse(y));
    return 0;
}
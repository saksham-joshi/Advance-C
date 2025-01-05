#include <stdio.h>
#include <math.h>

#define applyQuadratic(__a, __b, __c, __x) ((__a*__x*__x) + (__b * __x) + __c)

inline float sriDharacharyaPlusFormula(float __a , float __b , float __c) 
{
    return (-__b + sqrtf((__b * __b) - 4 * __a * __c)) / (__a * 2);
}

inline float sriDharacharyaMinusFormula(float __a , float __b , float __c) 
{
    return (-__b - sqrtf((__b * __b) - 4 * __a * __c)) / (__a * 2);
}

inline float solveQuadraticEquation(float __a , float __b , float __c)
{
    if(__a == 0) return ((-__c) / __b);

    float output = sriDharacharyaPlusFormula(__a , __b, __c);

    return (applyQuadratic(__a, __b, __c, output) == 0) ? output : sriDharacharyaMinusFormula(__a , __b , __c);
}

int main(void)
{
    float a, b, c;

    printf("\n ==> Enter values of a, b, c :- ");
    scanf_s("%f%f%f", &a , &b , &c);

    printf("\n ==> Value of x = %.5f", solveQuadraticEquation(a, b, c));

    return 0;
}

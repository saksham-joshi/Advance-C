#include<stdio.h>

typedef int BaseType;

inline void swapByReference(BaseType* __first , BaseType* __second)
{
    BaseType temp = *__first;
    *__first = *__second;
    *__second = temp;
}

inline void swapWithout3rdVariable(BaseType* __first , BaseType* __second)
{
    *__first = *__first + *__second;
    *__second = *__first - *__second;
    *__first = *__first - *__second;
}

int main(void)
{
    BaseType a = 10, b = 20;

    printf("\n | Before : \t A = %d \t B = %d", a, b);

    swapWithout3rdVariable(&a , &b);

    printf("\n | After : \t A = %d \t B = %d", a, b);

    return 0;
}
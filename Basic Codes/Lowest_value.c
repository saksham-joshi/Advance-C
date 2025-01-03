#include<stdio.h>

typedef double BaseType;

inline static BaseType min2(BaseType __value1 , BaseType __value2)
{
    return __value1 < __value2 ? __value1 : __value2;
}

inline static BaseType min3(BaseType __value1 , BaseType __value2 , BaseType __value3)
{
    return min2(__value1, min2(__value2 , __value3));
}

inline static BaseType min4(BaseType __value1 , BaseType __value2 , BaseType __value3 , BaseType __value4)
{
    return min2(__value1 , min3(__value2 , __value3, __value4));
}

int main(void)
{
    BaseType array[4] = {91,90,93,94};

    printf("\n =| Lowest value = %lf.", min4(array[0], array[1], array[2], array[3]));

    return 0;
}
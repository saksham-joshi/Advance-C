#include<stdio.h>

typedef double BaseType;

inline static BaseType max2(BaseType __value1 , BaseType __value2)
{ 
    return __value1 > __value2 ? __value1 : __value2; 
}

inline static BaseType max3(BaseType __value1 , BaseType __value2 , BaseType __value3)
{ 
    return max2(__value1, max2(__value2, __value3));
}

inline static BaseType max4(BaseType __value1 , BaseType __value2 , BaseType __value3 , BaseType __value4)
{ 
    return max2(__value1, max3(__value2, __value3, __value4));
}

int main(void)
{
    BaseType array[4] = {91,92,93,94};

    printf("\n =| Highest value = %lf.", max4(array[0], array[1], array[2], array[3]));

    return 0;
}

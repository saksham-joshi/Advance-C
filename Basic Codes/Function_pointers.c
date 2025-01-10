#include<stdio.h>

inline int min2(int __val1 , int __val2)
{
    return __val1 < __val2 ? __val1 : __val2;
}

inline int max2(int __val1 , int __val2)
{
    return __val1 < __val2 ? __val2 : __val1;
}

int main(void)
{
    int a = 20, b = 10;

    int (*min)(int, int) = min2;
    int (*max)(int, int) = max2;

    printf("Max = %d \n Min = %d", max(a,b) , min(a,b));

    return 0;
}
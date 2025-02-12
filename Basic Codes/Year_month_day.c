#include <stdio.h>

/*
   @param __no_of_days: total no of days you want to convert to year, month, days
   @param __array: the output generated by this function will save the 0th index with the year, following by month and days in next indices

*/
inline void yearMonthDay(unsigned long long __no_of_days , unsigned long long __array[3])
{
    __array[0] = __no_of_days / 365;

    unsigned long long temp = __no_of_days - __array[0]*365;

    __array[1] = temp / 30;

    __array[2] = temp - (__array[1]*30);
}

int main(void)
{
    unsigned long long no_of_days;
    unsigned long long ar[3];

    printf("\n ==> Enter the no. of days :- ");
    scanf_s("%llu", &no_of_days);

    yearMonthDay(no_of_days, ar);

    printf("\n >> %llu years, %llu months and %llu days.", ar[0] , ar[1] , ar[2]);

    return 0;
}
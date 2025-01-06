#include <stdio.h>

inline void floydTriangle(unsigned short int __no_of_rows)
{
    int number = 1;

    for(unsigned short int i= 1 ; i <= __no_of_rows ; ++i)
    {
        for(unsigned short int j = 0 ; j < i ; ++j) printf("%d ", number++);

        puts("");
    }
}

int main(void)
{
    unsigned short int no_of_rows;

    printf("\n ==> Enter the no. of rows :- ");
    scanf_s("%hu", &no_of_rows);

    floydTriangle(no_of_rows);

    return 0;
}
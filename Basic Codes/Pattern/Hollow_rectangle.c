#include<stdio.h>

inline void hollowRectangle(const unsigned short int __length , const unsigned short int __breadth)
{
    for(unsigned short int i = 0 ; i < __breadth ; ++i) printf("+  ");

    puts("");

    for(unsigned short int i = 0 ; i < __length ; ++i)
    {
        printf("+  ");

        for(unsigned short int j = 0 ; j < __breadth - 2 ; ++j) printf("   ");

        printf("+\n");
    }

    for(unsigned short int i = 0 ; i < __breadth ; ++i) printf("+  ");
}

int main(void)
{
    unsigned short int length, breadth;

    printf("\n ==> Enter the length & breadth :- ");
    scanf_s("%hu%hu", &length , &breadth);

    hollowRectangle(length , breadth);

    return 0;
}
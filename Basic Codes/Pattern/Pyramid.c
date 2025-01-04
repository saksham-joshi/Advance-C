#include<stdio.h>

inline void pyramid(const unsigned short int __height)
{
    for(unsigned short int i = 1 ; i <= __height ; ++i)
    {
        // printing the spaces
        for(unsigned short int j = 0 ; j < __height - i ; ++j) printf(" ");

        // printing the stars
        for(unsigned short int j = 0 ; j < i ; ++j) printf("* ");

        puts("");
    }
}

inline void reversedPyramid(const unsigned short int __height)
{
    for(unsigned short int i = 0 ; i < __height; ++i)
    {
        // printing the spaces
        for(unsigned short int j = 0 ; j < i ; ++j) printf(" ");

        // printing the stars
        for(unsigned short int j = 0 ; j < __height - i ; ++j) printf("* ");

        puts("");
    }
}

int main(void)
{
    unsigned short int height = 0;

    printf("\n ==> Enter the height of the pyramid :- ");
    scanf_s("%hu", &height);

    pyramid(height);
    reversedPyramid(height);

    return 0;
}
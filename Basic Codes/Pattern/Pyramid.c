#include "Pattern_header.h"

#define CHAR_TO_PRINT '*'

inline void pyramid(const unsigned short int __height)
{
    for(unsigned short int i = 1 ; i <= __height ; ++i)
    {
        // printing the spaces
        printSpaces( __height-i);

        // printing the stars
        printChar("%c ", CHAR_TO_PRINT, i);

        puts("");
    }
}

inline void reversedPyramid(const unsigned short int __height)
{
    for(unsigned short int i = 0 ; i < __height; ++i)
    {
        // printing the spaces
        printSpaces(i);

        // printing the stars
        printChar("%c ", CHAR_TO_PRINT, __height - i);

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
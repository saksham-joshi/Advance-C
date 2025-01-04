#include "Pattern_header.h"

#define CHAR_TO_PRINT '+'

inline void hollowRectangle(const unsigned short int __length , const unsigned short int __breadth)
{
    printChar("%c  ", CHAR_TO_PRINT , __breadth);

    puts("");

    for(unsigned short int i = 0 ; i < __length ; ++i)
    {
        printf("%c  ", CHAR_TO_PRINT);

        printConstChar("   ", __breadth - 2);

        printf("%c\n", CHAR_TO_PRINT);
    }

    printChar("%c  ", CHAR_TO_PRINT, __breadth);
}

int main(void)
{
    unsigned short int length, breadth;

    printf("\n ==> Enter the length & breadth :- ");
    scanf_s("%hu%hu", &length , &breadth);

    hollowRectangle(length , breadth);

    return 0;
}
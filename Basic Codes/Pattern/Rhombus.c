#include "Pattern_header.h"


#define CHAR_TO_PRINT '>'

inline void rhombus(const unsigned short int __no_of_lines)
{
    // printing the rhombus inclining to the left side
    for(unsigned short int i = 0 ; i < __no_of_lines ; ++i)
    {
        printSpaces(i*3);

        printChar("%c  ", CHAR_TO_PRINT , __no_of_lines);

        puts("");
    }

    // printing the rhombus inclining to the right side
    for(unsigned short int i = 0 ; i < __no_of_lines ; ++i)
    {
        printSpaces((__no_of_lines-i)*3);

        printChar("%c  ", CHAR_TO_PRINT, __no_of_lines);

        puts("");
    }
}

int main(void)
{
    unsigned short int no_of_lines = 0;

    printf("\n ==> Enter the no. of lines :- ");
    scanf_s("%hu", &no_of_lines);

    rhombus(no_of_lines);

    return 0;
}
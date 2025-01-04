#include "Pattern_header.h"

#define CHAR_TO_PRINT '*'

inline static void rightAngledTriangle(const unsigned short int __no_of_lines)
{
    for(unsigned short int i = 1 ; i <= __no_of_lines ; ++i)
    {
        printChar("%c ", CHAR_TO_PRINT , i);
        
        puts("");
    }

    puts("");

    for(unsigned short int i = 1 ; i <= __no_of_lines ; ++i)
    {
        // printing spaces
        printSpaces((__no_of_lines-i)*2);
        
        // printing stars
        printChar("%c ", CHAR_TO_PRINT, i);

        puts("");
    }
}
int main(void)
{
    unsigned short int no_of_lines = 0;

    printf("\n ==> Enter the no of lines :- ");
    scanf_s("%hu", &no_of_lines);

    rightAngledTriangle(no_of_lines);
    
    return 0;
}

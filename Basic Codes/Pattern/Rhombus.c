#include<stdio.h>

inline void rhombus(const unsigned short int __no_of_lines)
{
    // printing the rhombus inclining to the left side
    for(unsigned short int i = 0 ; i < __no_of_lines ; ++i)
    {
        for(unsigned short int j = 0 ; j < i ; ++j) printf("   ");

        for(unsigned short int j = 0 ; j < __no_of_lines ; ++j) printf(">  ");

        puts("");
    }

    // printing the rhombus inclining to the right side
    for(unsigned short int i = 0 ; i < __no_of_lines ; ++i)
    {
        for(unsigned short int j = 0 ; j < __no_of_lines-i ; ++j) printf("   ");

        for(unsigned short int j = 0 ; j < __no_of_lines ; ++j) printf(">  ");

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
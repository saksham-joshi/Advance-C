#include<stdio.h>

inline static void rightAngledTriangle(const unsigned short int __no_of_lines)
{
    for(unsigned short int i = 1 ; i <= __no_of_lines ; ++i)
    {
        for(unsigned short int j = 0 ; j < i ; ++j) printf("* ");
        
        puts("");
    }

    puts("");

    for(unsigned short int i = 1 ; i <= __no_of_lines ; ++i)
    {
        // printing spaces
        for(unsigned short int j = 0 ; j < __no_of_lines - i ; ++j) printf("  ");
        
        // printing stars
        for(unsigned short int j = 0 ; j < i ; ++j) printf("* ");

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

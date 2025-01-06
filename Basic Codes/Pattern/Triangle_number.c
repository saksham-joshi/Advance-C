#include <stdio.h>


/*

1
1 2
1 2 3
1 2 3 4 
1 2 3 4 5

*/
inline void printNumberedTriangle(unsigned short int __no_of_rows)
{
    for(unsigned short int i = 1 ; i <= __no_of_rows ; ++i)
    {
        for(unsigned short int j = 1 ; j <= i ; ++j) printf("%hu ", j);

        puts("");
    }
}

/*

1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

*/
inline void printNumberedInvertedTriangle(unsigned short int __no_of_rows)
{
    while(__no_of_rows)
    {
        for(unsigned short int j = 1; j <= __no_of_rows ; ++j) printf("%hu ", j);

        --__no_of_rows;

        puts("");
    }
}

int main(void){

    unsigned short int no_of_rows;

    printf("\n ==> Enter the no of rows :- ");
    scanf_s("%hu", &no_of_rows);

    printNumberedTriangle(no_of_rows);
    printNumberedInvertedTriangle(no_of_rows);

    return 0;
}
#include <stdio.h>

/*

if the given number is ODD ....

*                   *  
* *               * *  
* * *           * * *  
* * * *       * * * *  
* * * * *   * * * * *   
* * * * * * * * * * * 
* * * * *   * * * * *  
* * * *       * * * *  
* * *           * * *  
* *               * *  
*                   *  

------------------------------
if the given number is EVEN ....

*                 * 
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
* * * *     * * * *
* * *         * * *
* *             * *
*                 *

*/

inline void butterfly(const unsigned short int __width)
{

    unsigned short int height = ((float)__width * 2);

    height = (height+((height % 2 != 0) ? 1 : 0))/2;

    // printing the upper portion
    for(unsigned short int i = 1 ; i <= (height/2) ; ++i)
    {
        // printing the initial stars
        for(unsigned short int j = 0 ; j < i ; ++j) printf("* ");

        int space_count = (signed int)__width - (signed int) (i*2);

        // printing the spaces
        for(unsigned short int j = 0 ; j < space_count ; ++j) printf("  ");

        // printing the ending stars
        for(unsigned short int j = 0 ; j < i ; ++j) printf("* ");

        puts("");
    }

    int space_count = 2;

    if(__width % 2 != 0)
    { 
        for(unsigned short int i = 0 ; i < __width ; ++i) printf("* "); 
        puts(" ");
        space_count = 1;
    }

    // printing the remaining half portion
    for(unsigned short int i = 1 ; i <= (height/2) ; ++i)
    {
        int star_count = (signed)(__width/2)- (signed)i + (__width % 2 == 0 ? 0 : 1);
        
        for(unsigned short int j = 0 ; j < star_count ; ++j ) printf("* ");

        for(unsigned short int j = 0 ; j < space_count ; ++j) printf("  ");

        for(unsigned short int j = 0 ; j < star_count ; ++j ) printf("* ");

        puts("");

        space_count += 2;
    }
}

int main(void)
{
    unsigned short int width = 0;

    printf("\n ==> Enter the width of the butterfly :- ");
    scanf_s("%hu", &width);

    butterfly(width);

    return 0;
}
#include<stdio.h>
#include "Base_Vector.h"

inline static void vectorPrint ( VectorPtr_t __vector )
{
    printf("\n Vector -- [ ");

    for(VectorLen_t i = 0 ; i < __vector->_len ; ++i )
    {
        printf(" %d ", __vector->_array[i]);
    }

    puts(" ]");
}

int main ( void )
{
    Vector vec = vectorInit(4);

    for(int i = 16 ; i >= 0 ; --i) vectorPushBack(&vec , i);

    vectorPrint( &vec );

    printf("\n Length= %lu \t Allocated= %lu", vec._len , vec._allocated);

    vectorDestroy( &vec );

    return 0;
}
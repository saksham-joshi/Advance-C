#include<stdio.h>
#include "Base_Stack.h"

inline static StackBase_t getInput ( const char* __message )
{
    StackBase_t value;

    printf_s("\n ==> %s :- ", __message);
    scanf_s ( "%d" , &value );

    return value;
}

inline static void stackPrint ( StackPtr_t __obj )
{
    printf("\n Stack -- [ ");
    
    if ( __obj->_len )
    {
        NodePtr_t iterator = __obj->_top;

        while ( iterator )
        {
            printf("\n\t > %d" , iterator->_data);

            iterator = iterator->_next;
        }
    }

    puts("\n\t ] ");
}

inline static void stackPeek ( StackPtr_t __obj )
{
    if ( __obj->_len ) printf( "\n |+| Len= %lu \t Top= %d", __obj->_len , __obj->_top->_data );
    
    else puts ( "\n |+| Len= 0 \t Top= NULL");
}


int main ( void )
{
    Stack stk = { 0 };

    unsigned short int choice;

    while ( 1 )
    {
        printf_s(
            "\n 1. Push"
            "\n 2. Pop"
            "\n 3. Destroy"
            "\n 4. Print"
            "\n 5. Peek\n\t->_"
        );

        scanf_s("%hu", &choice);

        switch ( choice )
        {
            case 1 : stackPush( &stk , getInput("Enter the value")) ; break;

            case 2 : stackPop ( &stk ); break;

            case 3 : stackDestroy( &stk ); break;
            
            case 4 : stackPrint ( &stk ); break;

            case 5 : stackPeek( &stk ); break;

            default : puts("\n [[ Invalid choice! ]]"); goto EXECUTION_DONE;
        }

        if ( errno ) errno = 0;
        else puts("\n\t |+| Operation done Succesfully |+| \n");
    }

    EXECUTION_DONE:

    stackDestroy( &stk );

    return 0;
}
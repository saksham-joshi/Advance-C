#include<stdio.h>
#include "Base_Queue.h"

inline static QueueBase_t getInput ( const char* __message )
{
    QueueBase_t value;

    printf_s("\n ==> %s :- ", __message);
    scanf_s ( "%d" , &value );

    return value;
}

inline static void queuePrint ( QueuePtr_t __obj )
{
    printf("\n Queue -- [ ");
    
    if ( __obj->_len )
    {
        NodePtr_t iterator = __obj->_front;

        while ( iterator )
        {
            printf(" %d " , iterator->_value);

            iterator = iterator->_next;
        }
    }

    puts(" ] ");
}

inline static void queuePeek ( QueuePtr_t __obj )
{
    if ( __obj->_len ) printf( "\n |+| Len= %lu \t Front= %d \t Back= %d\n", __obj->_len , __obj->_front->_value , __obj->_back->_value );
    
    else puts ( "\n |+| Len= 0 \t Front= NULL \t Back= NULL");
}

int main ( void )
{
    Queue queue = initQueue();

    unsigned short int choice;

    while ( 1 )
    {
        printf_s(
            "\n 1. Push"
            "\n 2. Delete"
            "\n 3. Destroy"
            "\n 4. Print"
            "\n 5. Peek\n\t->_"
        );

        scanf_s("%hu", &choice);

        switch ( choice )
        {
            case 1 : queuePushBack ( &queue , getInput("Enter the value")); break;

            case 2 : queuePopFront ( &queue ); break;

            case 3 : queueDestroy ( &queue ) ; break;

            case 4 : queuePrint( &queue ); break;

            case 5 : queuePeek( &queue ); break;

            default : puts("\n [[ Invalid choice! ]]"); queueDestroy( &queue ); return 0;
        }

        if ( errno ) errno = 0;
        else puts("\n\t |+| Operation done Succesfully |+| \n");
    }

    queueDestroy( &queue );

    return 0;
}
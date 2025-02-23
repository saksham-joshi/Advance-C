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
            "\n 1. Push Back"
            "\n 2. Push Front"
            "\n 3. Pop Back"
            "\n 4. Pop Front"
            "\n 5. Destroy"
            "\n 6. Print"
            "\n 7. Peek\n\t->_"
        );

        scanf_s("%hu", &choice);

        switch ( choice )
        {
            case 1 : queuePushBack ( &queue , getInput("Enter the value")); break;

            case 2 : queuePushFront( &queue , getInput ("Enter the value")); break;

            case 3 : queuePopBack( &queue ); break;

            case 4 : queuePopFront ( &queue ); break;

            case 5 : queueDestroy ( &queue ) ; break;

            case 6 : queuePrint( &queue ); break;

            case 7 : queuePeek( &queue ); break;

            default : puts("\n [[ Invalid choice! ]]"); goto EXECUTION_DONE;
        }

        if ( errno ) errno = 0;
        else puts("\n\t |+| Operation done Succesfully |+| \n");
    }

    EXECUTION_DONE :

    queueDestroy( &queue );

    return 0;
}
#pragma once 

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdlib.h>
#include<errno.h>

#define QueueBase_t int 

struct BaseNode 
{
    QueueBase_t _value;
    struct BaseNode* _next;
};

typedef struct BaseNode* NodePtr_t;

typedef struct 
{
    NodePtr_t _front;
    NodePtr_t  _back;
    unsigned long _len;
} Queue;

typedef Queue* QueuePtr_t;

inline static Queue initQueue ( )
{
    Queue obj = { 0 };

    return obj;
}

inline static void queuePushBack ( QueuePtr_t __obj , QueueBase_t __value )
{
    NodePtr_t new_node = ( NodePtr_t ) malloc ( sizeof ( struct BaseNode ) );

    if ( new_node )
    {
        new_node->_value = __value;
        new_node->_next = NULL;

        if ( __obj->_front ) __obj->_back->_next = new_node;
        
        else __obj->_front = new_node;

        __obj->_back = new_node;

        ++ __obj->_len ;
    }
    else 
    {
        errno = ENOMEM;
        perror( "Cannot push element in Queue");
    }
}

inline static void queuePushFront ( QueuePtr_t __obj , QueueBase_t __value )
{
    NodePtr_t new_node = ( NodePtr_t ) malloc ( sizeof ( struct BaseNode ) );

    if ( new_node )
    {
        new_node->_value = __value;
        new_node->_next = __obj->_front;

        if ( __obj->_front ) __obj->_front = new_node;

        else __obj->_front = __obj->_back = new_node;

        ++ __obj->_len;
    }
    else 
    {
        errno = ENOMEM;
        perror( "Cannot push elements in Queue" );

    }
}

inline static void queuePopFront ( QueuePtr_t __obj )
{
    if ( __obj->_len )
    {
        NodePtr_t temp = __obj->_front;

        if ( __obj->_front == __obj->_back ) __obj->_front = __obj->_back = NULL;

        else __obj->_front = __obj->_front->_next;

        -- __obj->_len;

        free( temp );
    }
    else 
    {
        errno = EPERM;
        perror("Queue is Empty [ Underflow ]");
    }
}

inline static void queuePopBack ( QueuePtr_t __obj )
{
    if ( __obj->_len )
    {
        NodePtr_t iterator = __obj->_front;

        while ( iterator->_next && iterator->_next != __obj->_back ) iterator = iterator->_next;

        if ( iterator->_next ) 
        {
            free ( iterator->_next );
            iterator->_next = NULL;
            __obj->_back = iterator;
        }
        else
        {
            free ( __obj->_front );
            __obj->_front = __obj->_back = NULL;
        }

        -- __obj->_len;
        
    }
    else 
    {
        errno = EPERM;
        perror ( "Queue is empty [ Underflow ]");
    }
}

static void baseQueueDestroy ( NodePtr_t __node , const NodePtr_t __end_node )
{
    if ( __node == __end_node ) return ;

    baseQueueDestroy( __node->_next , __end_node);

    free( __node );
}

inline static void queueDestroy ( QueuePtr_t __obj )
{
    if ( __obj->_len )
    {
        baseQueueDestroy( __obj->_front , __obj->_back );

        free( __obj->_back );

        __obj->_front = __obj->_back = NULL;

        __obj->_len = 0;
    }
}

inline static QueueBase_t* queueGetBackValue ( QueuePtr_t __obj )
{
    if ( __obj->_len ) return &__obj->_back->_value;

    errno = EPERM;
    perror("[ Underflow ]");

    return NULL;
}

inline static QueueBase_t* queueGetFrontValue ( QueuePtr_t __obj )
{
    if ( __obj->_len ) return &__obj->_front->_value;

    errno = EPERM;
    perror ( "[ Underflow ]" );

    return NULL;
}

inline static _Bool queueIsEmpty( QueuePtr_t __obj )
{
    return ! __obj->_len ;
}

#endif
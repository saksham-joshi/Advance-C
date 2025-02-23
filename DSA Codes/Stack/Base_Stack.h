#include<errno.h>
#include<stdlib.h>

#define StackBase_t int 

struct BaseNode
{
    StackBase_t _data;
    struct BaseNode* _next;
};

typedef struct BaseNode* NodePtr_t;

typedef struct
{
    NodePtr_t _top;
    unsigned long _len;
} Stack;

typedef Stack* StackPtr_t;

inline static Stack stackInit ( )
{
    Stack obj = { 0 };

    return obj;
}

inline static void stackPush ( StackPtr_t __obj , StackBase_t __value )
{
    NodePtr_t new_node = ( NodePtr_t ) malloc ( sizeof ( struct BaseNode ) );

    if ( new_node )
    {
        new_node->_data = __value;

        new_node->_next = __obj->_top;

        __obj->_top = new_node;

        ++ __obj->_len;
    }
    else 
    {
        errno = ENOMEM;
        perror ("Cannot push element to stack");
    }
}

inline static void stackPop ( StackPtr_t __obj )
{
    if ( __obj->_len )
    {
        NodePtr_t temp = __obj->_top;

        __obj->_top = __obj->_top->_next;

        free ( temp );

        -- __obj->_len;
    }
    else 
    {
        errno = EPERM;
        perror( "Cannot pop element from empty stack" );
    }
}

inline static StackBase_t* stackGetTop ( StackPtr_t __obj )
{
    if ( __obj->_len ) return &__obj->_top->_data;
    
    errno = EPERM;
    perror ( "Cannot access top element from empty stack" );    

    return NULL;
}

inline static _Bool stackIsEmpty ( StackPtr_t __obj )
{
    return !__obj->_len;
}


static void stackBaseDestroy ( NodePtr_t __node )
{
    if ( __node ) 
    {
        stackBaseDestroy( __node->_next );

        free ( __node );
    }
}

inline static void stackDestroy ( StackPtr_t __obj )
{
    if ( __obj->_len )
    {
        stackBaseDestroy( __obj->_top );

        __obj->_top = NULL;

        __obj->_len = 0;
    }
}

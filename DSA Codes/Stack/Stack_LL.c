#include<stdio.h>
#include<stdbool.h>
#include<errno.h>
#include<stdlib.h>

#define STACK_UNDERFLOW 101
#define STACK_OVERFLOW  102

struct Node
{
    int _data;
    struct Node* _next;
};

typedef struct Node* NodePtr_t;

typedef struct
{
    NodePtr_t _top;
    unsigned int _len;
} MyStack;


inline static MyStack* myStackCreate() 
{
    MyStack* stack = (MyStack*) malloc ( sizeof( MyStack ));
    stack->_top = 0;
    stack->_len = 0;
    return stack;
}

inline static void myStackPush(MyStack* __obj, int __value)
{
    NodePtr_t newplate = (NodePtr_t) malloc (sizeof( struct Node ));

    if ( ! newplate )
    {
        errno = ENOMEM;
        perror("Cannot allocate a node");
        return;
    }

    newplate->_data = __value;
    newplate->_next = __obj->_top;

    __obj->_top = newplate;

    ++ __obj->_len;
}

inline static int myStackPop(MyStack* __obj)
{
    int output = 0;

    if ( __obj->_len  == 1)
    {
        output = __obj->_top->_data;

        free(__obj->_top);

        __obj->_top = 0;

        -- __obj->_len;
    }
    else if ( __obj->_len > 1)
    {
        output = __obj->_top->_data;

        NodePtr_t temp = __obj->_top;

        __obj->_top = __obj->_top->_next;

        free( temp );

        -- __obj->_len;
    }
    else errno = STACK_UNDERFLOW;
    
    return output;
}

inline static int myStackTop(MyStack* __obj)
{
    if ( __obj->_len ) return __obj->_top->_data;

    errno = STACK_UNDERFLOW;
    perror("STACK UNDERFLOW");

    return 0;

}

inline static bool myStackEmpty(MyStack* __obj)
{
    return ! __obj->_len;
}

static void destoryStack(NodePtr_t __node)
{
    if ( __node )
    {
        destoryStack( __node->_next );
        free( __node );
    }
}

inline static void myStackFree(MyStack* __obj)
{
    destoryStack( __obj->_top );

    free ( __obj );
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

int main ( void )
{
    MyStack* obj = myStackCreate();

    printf("\n > IsEmpty: %d", myStackEmpty( obj ));

    myStackPush( obj , 11);
    myStackPush( obj , 12);
    myStackPush( obj , 13);
    myStackPush( obj , 14);

    printf("\n > Top: %d", myStackTop( obj ));
    myStackPop( obj );
    printf("\n > Top: %d", myStackTop( obj ));
    myStackPop( obj );
    printf("\n > Top: %d", myStackTop( obj ));

    printf("\n > IsEmpty: %d", myStackEmpty( obj ));

    myStackPush(obj, 15);

    printf("\n > Top: %d", myStackTop( obj ));

    myStackFree( obj );

    return 0;
}
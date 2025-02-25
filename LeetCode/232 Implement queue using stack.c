struct BaseQueue
{
    int _data;
    struct BaseQueue* _next;
} ;

typedef struct BaseQueue QueueUnit;

typedef struct
{
    QueueUnit* _front;
    QueueUnit* _back;

} MyQueue;


inline static MyQueue* myQueueCreate()
{
    MyQueue* obj = ( MyQueue* ) malloc ( sizeof( MyQueue ) );

    obj->_front = obj->_back = 0;

    return obj;
}

inline static void myQueuePush(MyQueue* __obj, int __value )
{
    QueueUnit* new_value = (QueueUnit*) malloc ( sizeof ( QueueUnit ) );
    
    new_value->_data = __value;

    new_value->_next = 0;

    if ( __obj->_front ) __obj->_back->_next = new_value;

    else __obj->_front = new_value;

    __obj->_back = new_value;
}

inline static int myQueuePop(MyQueue* __obj)
{
    int output = __obj->_front->_data;

    if ( __obj->_back == __obj->_front ) 
    {
        free ( __obj->_back );

        __obj->_front = __obj->_back  = 0 ;
    }
    else 
    {
        QueueUnit* temp = __obj->_front;

        __obj->_front = __obj->_front->_next;

        free ( temp );
    }

    return output;
}

inline static int myQueuePeek(MyQueue* __obj)
{
    return __obj->_front->_data;
}

inline static bool myQueueEmpty(MyQueue* __obj)
{
    return !__obj->_front;
}

static void BaseMyQueueFree ( QueueUnit* __node )
{
    if ( __node )
    {
        BaseMyQueueFree( __node->_next );

        free ( __node );
    }
}
inline static void myQueueFree(MyQueue* __obj)
{
    BaseMyQueueFree( __obj->_front );  
    
    free ( __obj );
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

typedef struct
{
    char *_str;
    unsigned short int _len;
    unsigned short int _allocated;
    char *_writer;

} SimpleString;

inline static SimpleString initSimpleString( unsigned short int __allocate )
{
    SimpleString obj = {0};

    obj._str = (char*) calloc ( __allocate + 1 , sizeof(char));

    obj._writer = obj._str;
    
    obj._allocated = __allocate;

    return obj;
}

inline static char* copyString(char* __destination , const char* __source, unsigned short int __len)
{
    for(unsigned short int i = 0 ; i < __len ; ++i , ++__source , ++__destination) *__destination = *__source;
    
    return __destination;
}

inline static void pushBackSimpleString(SimpleString* __obj , char __ch)
{
    if ( __obj->_len < __obj->_allocated)
    {
        *( __obj->_writer ) = __ch;
        ++ __obj->_writer ;
        ++ __obj->_len;

        return;
    }

    // allocating string
    char* temp = (char*) calloc ( (__obj->_allocated *= 2) + 1, sizeof(char) );

    // now copying the old string to new string
   __obj->_writer = copyString(temp, __obj->_str, __obj->_len);

   // freeing up the old memory
    free(__obj->_str);

    // updating the string pointer to __obj->_str
    __obj->_str = temp;

    // assiging new character
    pushBackSimpleString( __obj , __ch);
}

inline static unsigned short int numLen ( long long int __number )
{
    unsigned short int len = 0;

    if ( __number )
    {
        
        while ( __number )
        {
            ++len;
            __number /= 10;
        }

        return len;
    }

    return 1;
}

static void recursiveInt2String ( long long int __num , SimpleString* __str)
{
    if ( __num == 0) return ;

    recursiveInt2String( __num / 10 , __str);

    pushBackSimpleString( __str , ( __num % 10) + 48);
}

inline static void intToString( long long int __num , SimpleString* __str )
{
    if ( __num == 0) 
    {
        pushBackSimpleString( __str , '0');
        return;
        
    }
    else 
    {
        if ( __num < 0)
        {
            pushBackSimpleString( __str , '-');
            __num = - __num;
        }
        recursiveInt2String( __num , __str);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
inline static char** summaryRanges(int* __array, unsigned short int __len , int* __return_size)
{
    if ( ! __len )
    {
        *__return_size = 0 ;
        return 0;
    }

    char** output = (char**) calloc ( __len , sizeof ( char* ) );

    const int*const ar_end = __array + __len;

    const int initial_string_size = numLen(__array [ __len - 1]) * 2 ;

    *__return_size = 0;

    for( ; __array < ar_end ; )
    {
        int start_value = *__array;

        int prev_value = *__array++;

        for( ; __array < ar_end && *__array == prev_value + 1; ++__array)
        {
            prev_value = *__array;
        }

        SimpleString str = initSimpleString( initial_string_size );

        intToString( start_value , &str );

        if ( start_value != prev_value )
        {
            pushBackSimpleString( &str , '-');
            pushBackSimpleString( &str , '>');

            intToString( prev_value , &str );
        }

        output[ (*__return_size)++ ] = str._str;

    }

    return output;
}
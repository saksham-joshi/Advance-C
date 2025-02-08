#define ONE '1'
#define ZERO '0'
#define STRING_END '\0'

typedef struct
{
    char* _str;
    unsigned short int _len;
    char* _writer;
} SimpleString;

inline static void adder( char** __writer , char** __lhs_writer , char** __rhs_writer , char* __carry)
{

    if (**__lhs_writer == ONE && **__rhs_writer == ONE )
    {
        // 1 + 1 + 1 (carry) = 1 with carry 1
        // 1 + 1 + 0 (carry) = 0 with carry 1
        **__writer = *__carry;
        *__carry = ONE;

        
    }
    else if ( **__lhs_writer == ZERO && **__rhs_writer == ZERO )
    {
        // 0 + 0 + 1 (carry) = 1
        // 0 + 0 + 0 (carry) = 0
        **__writer = *__carry; 
        *__carry = ZERO;
    }
    else
    {
        // 1 + 0 + 1(carry) = 0 with carry 1
        // 1 + 0 + 0(carry) = 1 with carry 0
        **__writer = ( *__carry == ONE) ? ZERO : ONE ;
    }
    --(* __writer);
    --(* __lhs_writer);
    --(* __rhs_writer);
}

inline static void addOne(char ** __write_on , char** __writer_from , char* __carry)
{
    if (**__writer_from == *__carry ) **__write_on = ZERO;
        
    else
    {
        **__write_on = ONE;
        *__carry = ZERO;
    }

    -- (*__write_on);
    -- (*__writer_from);
}

static void baseAddBinary( SimpleString* __str , SimpleString* __lhs , SimpleString* __rhs , char* __carry)
{
    ++__str->_len;

    if ( *__lhs->_writer == STRING_END && *__rhs->_writer == STRING_END)
    {
        // setup of output string
        __str->_str = (char*) calloc ( __str->_len + 1 , sizeof(char));
        __str->_writer = __str->_str + __str->_len - 1;

        // starting addition
        -- __lhs->_writer;
        -- __rhs->_writer;

        adder(&__str->_writer , &__lhs->_writer , &__rhs->_writer, __carry);

        return;
    }
    else if (*__lhs->_writer == STRING_END)
    {
        ++ __rhs->_writer;
        baseAddBinary( __str, __lhs , __rhs , __carry);
    }
    else if (*__rhs->_writer == STRING_END)
    {
        ++ __lhs->_writer;
        baseAddBinary( __str, __lhs , __rhs , __carry );
    }
    else
    {
        ++ __lhs->_writer;
        ++ __rhs->_writer;

        baseAddBinary( __str, __lhs, __rhs , __carry );
    }

    // performing addition only if the _writer is withing its bounds
    if (__lhs->_writer >= __lhs->_str && __rhs->_writer >= __rhs->_str)
    {
        adder(&__str->_writer , &__lhs->_writer , &__rhs->_writer , __carry);
    }
    else if (__lhs->_writer >= __lhs->_str)
    {
        addOne( &__str->_writer , &__lhs->_writer, __carry);
    }
    else if ( __rhs->_writer >= __rhs->_str)
    {
        addOne( &__str->_writer , &__rhs->_writer, __carry);
    }
}

inline static void shiftLeftString(char * __str)
{
    * __str = *(__str + 1);
    ++ __str;

    while( * __str )
    {
        * __str = *(__str + 1);
        ++ __str;

    }
}

inline static char* addBinary(char* __lhs, char* __rhs)
{
    char carry = ZERO;

    SimpleString output = {0};

    SimpleString lhs = { __lhs , 0, __lhs };

    SimpleString rhs = { __rhs , 0, __rhs };

    baseAddBinary( &output , &lhs , &rhs , &carry);

    if (carry == ONE) *output._writer = ONE;

    if ( ! (*output._str) ){ shiftLeftString(output._str);}
    
    return output._str;
}
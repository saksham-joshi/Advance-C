typedef struct
{
    char *_str;
    unsigned short int _len;
    unsigned short int _allocated;

} SimpleString;


inline static SimpleString initSimpleString( unsigned short int __allocate )
{
    SimpleString obj = {0};

    obj._str = (char*) calloc ( __allocate + 1 , sizeof(char));
    
    obj._allocated = __allocate;

    return obj;
}

inline static void copyString(char* __destination , const char* __source, unsigned short int __len)
{
    for(unsigned short int i = 0 ; i < __len ; ++i , ++__source , ++__destination) *__destination = *__source;
}

inline static void pushBackSimpleString(SimpleString* __obj , char __ch)
{
    if ( __obj->_len == __obj->_allocated)
    {
        // allocating string
        char* temp = (char*) calloc ( (__obj->_allocated *= 2) + 1, sizeof(char) );

        // now copying the old string to new string
        copyString(temp, __obj->_str, __obj->_len);

        // freeing up the old memory
        free(__obj->_str);

        // updating the string pointer to __obj->_str
        __obj->_str = temp;
    }

    __obj->_str [ __obj->_len++ ] = __ch;
}



/*|====[ A Sample code of how to use SimpleString ]====|*/


// int main ( void )
// {
//     // Make sure to always initialize your string using initSimpleString() function
//     SimpleString str = initSimpleString(10);

//     // to insert a character to the string
//     pushBackSimpleString(&str , 'A');

//     // if you have to destory the string, then you have to free up the ._str
//     free ( str._str );
// }
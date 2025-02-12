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

#define ALPHABET__ "ZABCDEFGHIJKLMNOPQRSTUVWXY"


static void baseConvertToTitle(SimpleString* __str , unsigned int __column_no)
{
    if (  ! __column_no ) return;

    baseConvertToTitle( __str , (__column_no % 26 == 0 ? __column_no - 1 : __column_no )/ 26);

    pushBackSimpleString( __str , ALPHABET__[ __column_no % 26]);
}

inline static char* convertToTitle(unsigned int __column_no)
{

    SimpleString output = initSimpleString(8);

    baseConvertToTitle( &output , __column_no );

    return output._str;
}
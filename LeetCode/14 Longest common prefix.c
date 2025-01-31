char* EMPTY_STRING__ = "";

inline static unsigned short int stringLen(const char* __str)
{
    unsigned short int len = 0;

    while(*__str++) ++len;

    return len;
}

inline static unsigned short int checkEqualityIndex(const char* __base , const char* __str , unsigned short int __limit)
{
    unsigned short int i = 0 ;

    for(; i < __limit ; ++i)
    {
        if (*__base != *__str ) return i;

        ++__base;
        ++__str;
    }

    return i;
    
}

inline static char* longestCommonPrefix(char** strs, int strsSize) {
    
    char* baseString = *strs++;

    unsigned short int end_index = stringLen(baseString);

    char** iterator_at_strs = strs;

    for ( int i = 1 ; i < strsSize ; ++i , ++iterator_at_strs )
    {

        unsigned short int temp_index = checkEqualityIndex(baseString , *iterator_at_strs , end_index);

        if ( ! temp_index ) return EMPTY_STRING__;
        
        if ( temp_index < end_index ) end_index = temp_index;

    }

    baseString[end_index] = '\0';

    return baseString ;
}
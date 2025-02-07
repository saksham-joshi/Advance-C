inline static int lengthOfLastWord(const char* __str )
{
    const char* iterator = __str;

    unsigned short int index;

    while( *iterator ) { if ( *iterator != ' ') index = iterator - __str; ++iterator;  }
        
    const char* new_iterator = __str + index;

    while ( new_iterator >= __str) { if ( *new_iterator == ' ') break; --new_iterator; }

    return ( __str + index) - new_iterator;
}
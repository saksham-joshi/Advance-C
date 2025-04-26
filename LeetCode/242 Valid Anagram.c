inline static bool isAnagram(const char* __s, const char* __t)
{
    int char_map[26] = { 0 };

    while( *__s && *__t )
    {
        ++(char_map[*__s - 'a']);
        --(char_map[*__t - 'a']);
        ++__s;
        ++__t;
    }

    if ( *__s != *__t ) return false;

    const int* iterator = char_map;

    for(unsigned char i = 0; i < sizeof(char_map)/ sizeof(char_map[0]); ++i , ++iterator) if ( *iterator != 0 ) return false;

    return true;
}
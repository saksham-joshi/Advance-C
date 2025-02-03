inline static char repeatedCharacter(const char* __str)
{
    char array[26] = { '\0' };

    while ( *__str )
    {
       char* temp = &array[*__str - 'a'];
       
       if ( *temp ) return *__str;

       ++(*temp);

       ++ __str;
    }

    return '\0';
}
inline static bool baseIsIsormorphic ( const char* __s , const char* __t )
{
    char char_map[256] = {0};

    while ( *__s )
    {
        if ( char_map[ *__s ] )
        {
            if ( char_map[ *__s ] != *__t) return false;
        }
        else
        {
            char_map [ *__s ] = *__t;
        }

        ++ __s;
        ++ __t;
    }

    return true;
}

inline static bool isIsomorphic( const char* __s , const char* __t)
{
    return baseIsIsormorphic( __s , __t ) && baseIsIsormorphic( __t , __s );
}
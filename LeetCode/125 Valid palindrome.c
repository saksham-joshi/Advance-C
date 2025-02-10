inline static char toLowerCase( char __ch)
{
    return (__ch >= 'A' && __ch <= 'Z') ? __ch + 32 : __ch;
}

inline static bool isAlphaNumeric( char __ch )
{
    return ( __ch >= 'a' && __ch <= 'z') || ( __ch >= '0' && __ch <= '9');
}

inline static bool isPalindrome(const char* __str)
{
    const char* rev_iterator = __str + strlen( __str) - 1;

    while (  __str < rev_iterator )
    {
        char left_char = toLowerCase( * __str );
        char right_char = toLowerCase( *rev_iterator );

        bool is_front_alphanum = isAlphaNumeric( left_char );
        bool is_back_alphanum  = isAlphaNumeric( right_char );

        if (is_front_alphanum && is_back_alphanum && left_char == right_char ) {  ++ __str;  --rev_iterator; continue; }

        else if (is_front_alphanum && is_back_alphanum) return false;
        
        if ( ! is_front_alphanum ) ++ __str;

        if ( ! is_back_alphanum ) -- rev_iterator;

    }
    
    return true;
}
inline static int strStr(const char* __haystack, const char* __needle) 
{
    if ( ! *__needle ) return strlen(__haystack);

    const char* original_haystack = __haystack;
    const char* original_needle = __needle;

    while ( * __haystack )
    {
        if ( *__needle == *__haystack )
        {
            const char* iterator = __haystack + 1;

            ++ __needle;

            while (*iterator && *__needle)
            {
                if ( *iterator != *__needle) break;

                ++ iterator;
                ++ __needle;
            }

            if (*__needle == '\0' || *iterator == *__needle) return __haystack - original_haystack;

            __needle = original_needle;

        }

        ++ __haystack ;
    }

    return -1;
}
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

inline static int baseFirstBadVersion( unsigned int __lhs, unsigned int __rhs )
{
    for(; __lhs < __rhs - 1 ; )
    {
        int middle = ( __rhs + __lhs) / 2;

        if( isBadVersion(middle) ) __rhs = middle;

        else __lhs = middle;
    }

    return isBadVersion(__lhs) ? __lhs : __rhs;
}

inline static int firstBadVersion(unsigned int __version)
{
    int middle = (__version + 1) / 2;

    if ( isBadVersion( middle) ) return baseFirstBadVersion(1, middle);

    return baseFirstBadVersion(middle , __version);
}
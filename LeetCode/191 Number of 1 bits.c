inline static int hammingWeight( unsigned int __value )
{
    char count = 0;

    while ( __value )
    {
        count += ( __value % 2 );

        __value >>= 1;
    }

    return count;
}
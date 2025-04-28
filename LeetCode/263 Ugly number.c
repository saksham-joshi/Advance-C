inline static bool isUgly(int __num)
{
    if ( __num == 0 ) return false;

    while ( __num != 1 )
    {
        if ( __num % 2 == 0 ) __num /= 2;

        else if ( __num % 3 == 0 ) __num /= 3;

        else if ( __num % 5 == 0) __num /= 5;

        else return false;
    }

    return true;
}
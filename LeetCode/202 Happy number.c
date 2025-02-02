inline static int getSquareSum(int __num)
{
    int output = 0;

    while ( __num )
    {
        int temp = __num % 10;

        output += ( temp * temp );

        __num /= 10;
    }

    return output;
}

static bool baseIsHappy(int __num , unsigned int __recursive_level)
{
    if ( __recursive_level--)
    { 
        int temp = getSquareSum(__num);
        
        if ( temp == 1 ) return true;
        else if ( ! temp ) return false;

        return baseIsHappy(temp, __recursive_level);
    }

    return false;
}

inline static bool isHappy(int __num)
{
    return baseIsHappy(__num , 30);
}
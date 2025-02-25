inline static int addDigits(int __num)
{
    if ( __num < 10) return __num;

    int output = __num % 9;

    return ( output == 0 ) ? 9 : output;
}
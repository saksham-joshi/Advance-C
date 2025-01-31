inline static bool isPalindrome(int __num)
{
    if (__num < 0) return false;

    unsigned long rev = 0;
    unsigned long original = __num;
    
    while ( __num )
    {
        rev = ( rev * 10 ) + ( __num % 10 );
        __num /= 10;
    }

    return original == rev;

}
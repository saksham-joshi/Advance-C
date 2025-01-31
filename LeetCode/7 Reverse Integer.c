#define INT_MAX_RANGE (int) 2147483647
#define INT_MIN_RANGE (int) -2147483648


inline static int reverse(int __x)
{
    long long val = (__x < 0) ? - (long long) __x : __x ;

    long long rev = 0;

    while(val != 0)
    {
        rev = (rev * 10) + (val % 10);
        val /= 10;
    }

    return (rev > INT_MAX_RANGE || rev < INT_MIN_RANGE) ? 0 : ( (__x < 0) ? -rev : rev) ;
}
#define MAX_INT32 (long long)  2147483647
#define MIN_INT32 (long long) -2147483648

inline static int checkNegative(char __ch , char* __is_negative)
{
    if( __ch == '-')
    {
        *__is_negative = 1;
        return 1;
    }
    else if(__ch == '+') return 1;

    return 0;
}

inline static int roundOffLongToInt(long long __value)
{
    if (__value > MAX_INT32) return MAX_INT32;

    if (__value < MIN_INT32) return MIN_INT32;

    return __value;
}

inline static int myAtoi(char* __str)
{
    // jumping whitespaces
    while(*__str && *__str == ' ') ++__str;

    if ( ! *__str) return 0;

    char is_negative = '\0';
   
    __str += checkNegative(*__str , &is_negative);

    long long int output = 0;

    while(*__str && output < MAX_INT32)
    {
        if(*__str >= '0' && *__str <= '9')  output = (output * 10) + (*__str - '0');
        
        else break;
        
        ++__str;
    }

    return roundOffLongToInt((is_negative ? -output : output));
}
#include<stdio.h>
#include<errno.h>

#define TYPE_CONVERSION_ERROR 101

inline static long long stringToLongLong(const char* __str)
{
    if(!__str){ errno = EFAULT; return 0;}

    long long output = 0;

    const char* iterator = __str + (*__str == '-' ? 1 : 0);

    while(*iterator)
    {
        if((*iterator >= '0' && *iterator <= '9'))
        {
            output = (output*10) + (unsigned short)(*iterator - '0');
            ++iterator;
            continue;
        }
        errno = TYPE_CONVERSION_ERROR; 
        break;
    }

    return ((*__str == '-') ? -output : output);
}

inline static double stringToDouble(const char* __str)
{
    if(!__str) {errno = TYPE_CONVERSION_ERROR; return 0;}

    double output = 0;

    const char* iterator = __str + (*__str == '-' ? 1 : 0);

    while(*iterator && *iterator != '.')
    {
        if((*iterator >= '0' && *iterator <= '9')){
            output = (output * 10) + (*iterator - '0');
            ++iterator;
            continue;
        }
        errno = TYPE_CONVERSION_ERROR;
        break;
    }

    if(errno) return 0;

    // #- Now solving after decimal part ...
    if(*iterator == '.') ++iterator;

    double ten = 10;

    while(*iterator)
    { 
        if((*iterator >= '0' && *iterator <= '9'))
        {
            output += ((double)(*iterator - '0')/ten);
            ten *= 10;
            ++iterator;
            continue;
        }
        errno = TYPE_CONVERSION_ERROR;

        break;
    }

    return (*__str == '-' ? -output : output);
}

int main(void)
{
    printf("\n Output = '%lld'", stringToLongLong("123456789"));
    printf("\n Output = '%lf'", stringToDouble("-1231.000123"));
}
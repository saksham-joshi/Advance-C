#include <stdio.h>
#include "../Advance Codes/Input_string.h"
#include<math.h>

#define CONVERSION_ERROR 101

/*
    @param __str: character array pointer containing 
    @param __len: contains the length of the character array pointer len

    - Converts the given string containing '1' and '0' to integer number.
    
    - If the given string contains characters other than 1 & 0, then it
      will set the errno to CONVERSION_ERROR and return the number as it is.

*/
inline long long binaryToInteger(const char* __str, unsigned long __len)
{
    // if the first character is '1', it means the integer value is negative otherwise positive
    int is_negative = (*__str == '1') ? 1 : 0;

    // decrementing the __len by 1 because we already checked
    --__len;

    long long output = 0;

    while(*++__str)
    {
        --__len;

        if(*__str == '0') continue;

        else if(*__str == '1') output += pow(2, __len);
        
        else
        {
            errno = CONVERSION_ERROR;
            break;
        }
    }

    return (is_negative) ? -output : output;
}

int main(void)
{
    SimpleStringStore str = getLine("\n ==> Enter the number in binary :- ");

    printf("\n |=| Decimal of '%s' = %lld", str.str , binaryToInteger(str.str, str.len));

    return 0;
}
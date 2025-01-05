#include <stdio.h>
#include "../Advance Codes/Modern_String/Modern_String.h"

#define CONVERSION_ERROR 101

inline void Base_decimalToBinary(long long __num , ModernString* __binary_data)
{
    if(__num == 1 || __num == 0){
        pushBackString(__binary_data , (__num == 0 ) ? '0' : '1');
        return;
    }

    Base_decimalToBinary(__num / 2 , __binary_data);

    pushBackString(__binary_data , (__num % 2 == 0) ? '0' : '1');

}

inline ModernString decimalToBinary(long long __num)
{
    ModernString str = makeReservedString(64);

    if(__num < 0) 
    {
        pushBackString(&str , '1');
        __num = -__num;
    }
    else
    {
        pushBackString(&str , '0');
    }

    Base_decimalToBinary(__num , &str);

    return str;
}

int main(void)
{
    for(long long i = -5 ; i < 10 ; ++i)
    {
        ModernString str = decimalToBinary(i);
        
        printf("\n %lld = '%s'", i , getConstCharString(&str));

        destroyString(&str);
    }
}
#include<stdio.h>

typedef char Bool;

// consumes only 1 byte
#define TRUE (Bool)'1'
#define FALSE (Bool)'\0'

typedef int ArType;

inline static Bool arrayPalindrome(ArType *__array_ptr, const unsigned long __size)
{
    ArType *backward_iterator = __array_ptr + (__size-1);

    ArType *forward_iterator = __array_ptr;

    while(forward_iterator < backward_iterator){
        if(*forward_iterator != *backward_iterator) return FALSE ;
        ++forward_iterator;
        --backward_iterator;
    }

    return TRUE;
}

int main(){

    ArType ar[4] = {1,2,2,3};
    
    printf("\n Given array is %spalindrome.", arrayPalindrome(&ar[0], 4)? "a " : "not a ");

    return 0;
}
#include "../Advance Codes/Input_string.hpp"

typedef char Bool;

#define TRUE (Bool)'1'
#define FALSE (Bool)'\0'


inline static Bool stringPalindrome(const char* __str, unsigned long __length)
{
    if (__length == 0) return TRUE;
    
    const char* backward_iterator = __str + (__length-1);

    const char* forward_iterator = __str;

    while(forward_iterator < backward_iterator){
        if(*forward_iterator != *backward_iterator) return FALSE;
        ++forward_iterator;
        --backward_iterator;
    }

    return TRUE;
}

int main(){

    SimpleStringStore obj = getLine("\n ==> Enter the string :- ");
    
    printf("\n |= Given string \"%s\" is %s palindrome!", obj.str, (stringPalindrome(obj.str, obj.len) ? "a" : "not a"));

    return 0;
}
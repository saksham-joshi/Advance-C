#pragma once

#ifndef _INPUT_STRING_H_
#define _INPUT_STRING_H_

#include<stdio.h>
#include<stdlib.h>

inline static char* copyDataAndFree(char* __str, unsigned long __length, unsigned long* __buffer_size)
{
    char* original = __str;
    *__buffer_size = __length * 2;

    char *new_string = (char*) calloc( *__buffer_size , sizeof(char));
    
    if( ! new_string )
    {
        errno = ENOMEM;
        return NULL;
    }

    char* iterator = new_string;

    while(*__str)
    {
        *iterator = *__str;
        ++iterator;
        ++__str;
    }

    *iterator = '\0';

    free(original);

    return new_string;
}

typedef struct 
{
    char* str;

    unsigned long len;

} SimpleStringStore;


inline static SimpleStringStore getDataFromConsole(unsigned long __buffer_size, const char __terminator)
{
    char *str = (char*) calloc(__buffer_size, sizeof(char));

    char* iterator = str;

    unsigned long index = 0;

    char ch = getchar();

    while(ch != __terminator)
    {
        if(index == __buffer_size)
        {
            str = copyDataAndFree(str, index , &__buffer_size);
            iterator = str + index;
        }

        *iterator = ch;

        ++iterator;

        ++index;

        ch = getchar();
    }

    *iterator = '\0';

    SimpleStringStore obj;
    obj.str = str;
    obj.len = index;

    return obj;
}

inline static SimpleStringStore getLine(const char* __message)
{
    printf("%s",__message);
    return getDataFromConsole(8, '\n');
}

#endif

// ================== A Sample of how to get input ======================= //
// int main()
// {
//     SimpleStringStore obj = getLine("\n ==> Enter a string :- ");

//     printf("\n Output = '%s'\n =| Length = %lu", obj.str , obj.len);

//     free(obj.str);

//     return 0;
// }
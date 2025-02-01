
/******************************************************************************
 * Project Name: C Modern String
 * File Name: Modern_String_utility.h
 * Author: Saksham Joshi
 * Email: social.sakshamjoshi@gmail.com
 *
 * License:
 * This file is licensed under the GNU GENERAL PUBLIC LICENSE. You are free to use,
 * modify, and distribute this code for any purpose, with or without attribution.
 * 
 * DISCLAIMER: This code is provided "as is," without any warranty of any kind,
 * express or implied. The author is not responsible for any damages arising
 * from the use of this software.
 *
 * Copyright (c) [2025] Saksham Joshi. All rights reserved.
 *****************************************************************************/
#include "Modern_String_base.h"

typedef struct 
{
    struct Alphabets
    {
        struct Vowels{
            unsigned long _capital;
            unsigned long _small;
        } _vowels ;

        struct Consonants{
            unsigned long _capital;
            unsigned long _small;
        } _consonants;

    } _alphabets;

    unsigned long _digits;
    unsigned long _spaces;
    unsigned long _newlines;
    unsigned long _misc;

    struct Brackets
    {
        struct CurlyBrackets
        {
            unsigned long _open;
            unsigned long _close;
        } _curly;
        
        struct RoundBrackets
        {
            unsigned long _open;
            unsigned long _close;
        } _round;

        struct SquareBrackets
        {
            unsigned long _open;
            unsigned long _close;
        } _square;

    } _brackets;

} ModernStringStats;


inline char* ModernStringUtil_copyDataAndFree(char* __str, unsigned long __length)
{
    char* original = __str;
    char *copy = (char*) calloc(__length*2, sizeof(char));
    
    if(copy == NULL) return NULL;

    char* iterator = copy;

    while(*__str){
        *iterator = *__str;
        ++iterator;
        ++__str;
    }

    *iterator = '\0';

    free(original);

    return copy;
}

typedef struct {
    char* str;
    unsigned long len;
    unsigned long allocated_buffer_size;
} SimpleStringStore;

inline SimpleStringStore ModernStringUtil_getDataFromConsole(unsigned long __buffer_size, const char __terminator)
{
    char *str = (char*) calloc(__buffer_size, sizeof(char));

    char* iterator = str;

    unsigned long index = 0;

    char ch = getchar();

    while(ch != __terminator)
    {
        if(index == __buffer_size)
        {
            str = ModernStringUtil_copyDataAndFree(str, index);
            iterator = str + index;
            __buffer_size *= 2;
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
    obj.allocated_buffer_size = __buffer_size;

    return obj;
}

inline void ModernStringUtil_incrementIterators(const char** __iter1 , const char** __iter2)
{
    while(**__iter1 && **__iter2 && **__iter1 == **__iter2)
    {
        ++(*__iter1);
        ++(*__iter2);
    }
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
int ModernStringUtil_charCmp(void* __context, const void* __lhs , const void* __rhs)
{
    return *((char*) __lhs) - *((char*) __rhs);
}
#pragma clang diagnostic pop





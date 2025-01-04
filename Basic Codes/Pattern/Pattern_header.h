
#pragma once

#ifndef _PATTERN_H_
#define _PATTERN_H_

#include<stdio.h>

// prints a character
inline void printChar(const char* __str, char __ch, unsigned short int __count)
{
    for(unsigned short int i = 0 ; i < __count ; ++i) printf(__str, __ch);
}

inline void printConstChar(const char* __str , unsigned short int __count)
{
    for(unsigned short int i = 0 ; i < __count ; ++i) printf("%s", __str);
}

inline void printSpaces(unsigned short int __count)
{
    for(unsigned short int i = 0 ; i < __count ; ++i) putchar(' ');
}

#endif
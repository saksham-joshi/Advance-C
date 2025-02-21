
#pragma once

#ifndef _TYPE_DETECT_H_
#define _TYPE_DETECT_H_

#include<stdio.h>
    
#define GET_FORMAT_SPECIFIER( __type ) _Generic( (__type) , \
    int                     : "%d"   , \
    short int               : "%hd"  , \
    unsigned short int      : "%hu"  , \
    unsigned int            : "%u"   , \
    long int                : "%ld"  , \
    long long               : "%lld" , \
    unsigned long long      : "%llu" , \
    char                    : "%c"   , \
    char*                   : "%s"   , \
    const char*             : "%s"   , \
    float                   : "%f"   , \
    double                  : "%lf"  , \
    long double             : "%Lf"  , \
    default                 : "Cannot find format specifier for type '" #__type "'"  \
)

#define Print( __value ) printf( GET_FORMAT_SPECIFIER( __value ) , __value );


#endif
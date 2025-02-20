#pragma once

#ifndef _BASE_LL_H_
#define _BASE_LL_H_

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define NodeData_t int
#define IS_NODE_DATA_PRINTABLE 1    // set it 0 if the value is not printable otherwise set it one


#if defined(SINGLY_LL)

    struct Node
    {
        NodeData_t _data;
        struct Node* _next;
    };

#elif defined(DOUBLE_LL)
    
    struct Node
    {
        struct Node* _prev;
        NodeData_t _data;
        struct Node* _next;
    };
#elif defined(MULTILEVEL_LL)

    #undef NodeData_t
    #define NodeData_t char
#else
    #error "Among 'SINGLY_LL', 'DOUBLE_LL', 'MULTILEVEL_LL' at least one of type of Linked List must be defined!"
#endif 

#if IS_NODE_DATA_PRINTABLE
    #if defined(NodeData_t)
            #if NodeData_t == int
                #define FORMAT_SPECIFIER_LINKED_LIST "%d"
            #elif NodeData_t == unsigned int
                #define FORMAT_SPECIFIER_LINKED_LIST "%u"
            #elif NodeData_t == short int
                #define FORMAT_SPECIFIER_LINKED_LIST "%hd"
            #elif NodeData_t == unsigned short int
                #define FORMAT_SPECIFIER_LINKED_LIST "%hu"
            #elif NodeData_t == long
                #define FORMAT_SPECIFIER_LINKED_LIST "%ld"
            #elif NodeData_t == long long
                #define FORMAT_SPECIFIER_LINKED_LIST "%lld"
            #elif NodeData_t == unsigned long long
                #define FORMAT_SPECIFIER_LINKED_LIST "%llu"
            #elif NodeData_t == char
                #define FORMAT_SPECIFIER_LINKED_LIST "%c"
            #elif NodeData_t == float
                #define FORMAT_SPECIFIER_LINKED_LIST "%f"
            #elif NodeData_t == long float
                #define FORMAT_SPECIFIER_LINKED_LIST "%lf"
            #elif NodeData_t == double
                #define FORMAT_SPECIFIER_LINKED_LIST "%lf"
            #elif NodeData_t == long double
                #define FORMAT_SPECIFIER_LINKED_LIST "%Lf"
            #else
                #define FORMAT_SPECIFIER_LINKED_LIST "%s"
            #endif

    #else   
        #error "You have to define 'NodeData_t to work on any Linked List!"
    #endif
#endif



#define LINKED_LIST_DEBUG_MODE 1

typedef struct Node* NodePtr_t;

#define SIZEOF_NODE sizeof(struct Node)

inline void Utility_destroyRecursively(NodePtr_t __ptr)
{
    if( ! __ptr) return;

    Utility_destroyRecursively(__ptr->_next);

    free(__ptr);
}

inline NodeData_t getInput(const char* __str)
{
    printf("%s", __str);

    NodeData_t value;

    scanf_s(FORMAT_SPECIFIER_LINKED_LIST, &value);

    return value;
}

#endif
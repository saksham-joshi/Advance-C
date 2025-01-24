#pragma once

#ifndef _BASE_LL_H_
#define _BASE_LL_H_

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

typedef int NodeData_t;

#if !defined(NodeData_t)
        #if NodeData_t == int
            #define FORMAT_SPECIFIER_LINKED_LIST "%d"
        #elif NodeData_t == long
            #define FORMAT_SPECIFIER_LINKED_LIST "%ld"
        #elif NodeData_t == long long
            #define FORMAT_SPECIFIER_LINKED_LIST "%lld"
        #elif NodeData_t == unsigned long long
            #define FORMAT_SPECIFIER_LINKED_LIST "%llu"
        #elif NodeData_t == float
            #define FORMAT_SPECIFIER_LINKED_LIST "%f"
        #elif NodeData_t == char
            #define FORMAT_SPECIFIER_LINKED_LIST "%c"
        #elif NodeData_t == double
            #define FORMAT_SPECIFIER_LINKED_LIST "%lf"
        #else
            #define FORMAT_SPECIFIER_LINKED_LIST "%s"
        #endif
    #else
        #error "You have to define 'NodeData_t to work on Doubly Linked List!"
#endif

struct Node
{
    struct Node* _prev;
    NodeData_t _data;
    struct Node* _next;
};

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
#pragma once
#pragma clang optimize on

#ifndef _BASE_LL_H_
#define _BASE_LL_H_

#include<stdlib.h>
#include<errno.h>

#define NodeData_t int

#if defined(SINGLY_LL)

    struct Node
    {
        NodeData_t _data;
        struct Node* _next;
    };

    typedef struct Node* NodePtr_t;

    struct LinkedList {
        size_t _len;
        NodePtr_t _head;
        NodePtr_t _tail;
    };

    inline struct LinkedList makeLinkedList()
    {
        struct LinkedList obj = {0};

        return obj;
    }
    
    typedef struct LinkedList* LLPtr;

#elif defined(DOUBLE_LL)
    
    struct Node
    {
        struct Node* _prev;
        NodeData_t _data;
        struct Node* _next;
    };

    typedef struct Node* NodePtr_t;

    struct DoublyLinkedList
    {
        NodePtr_t _head;
        NodePtr_t _tail;
        size_t _len;
    };

    typedef struct DoublyLinkedList* DLLptr_t;

    inline static struct DoublyLinkedList makeDoublyLinkedList(void)
    {
        struct DoublyLinkedList obj = {0};

        return obj;
    }

#elif defined(MULTILEVEL_LL)

    #undef NodeData_t
    #define NodeData_t char

#else
    #error "Among 'SINGLY_LL', 'DOUBLE_LL', 'MULTILEVEL_LL' at least one of type of Linked List must be defined!"
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

#endif
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

typedef int NodeData_t;

struct Node{
    NodeData_t _data;
    struct Node* _next;
};

#if !defined(NodeData_t)
        #if NodeData_t == int
            #define FORMAT_SPECIFIER "%d"
        #elif NodeData_t == long
            #define FORMAT_SPECIFIER "%ld"
        #elif NodeData_t == long long
            #define FORMAT_SPECIFIER "%lld"
        #elif NodeData_t == unsigned long long
            #define FORMAT_SPECIFIER "%llu"
        #elif NodeData_t == float
            #define FORMAT_SPECIFIER "%f"
        #elif NodeData_t == char
            #define FORMAT_SPECIFIER "%c"
        #elif NodeData_t == double
            #define FORMAT_SPECIFIER "%lf"
        #else
            #define FORMAT_SPECIFIER "%s"
        #endif
    #else
        #error "You have to define 'NodeData_t to work more on Linked List!"
#endif

#define SIZEOF_NODE sizeof(struct Node)

typedef struct Node* NodePtr;

struct LinkedList {
    size_t _len;
    NodePtr _head;
    NodePtr _tail;
};

typedef struct LinkedList* LLPtr;

inline void Utility_destroyRecursively(NodePtr __ptr)
{
    if( ! __ptr->_next ) return;

    Utility_destroyRecursively(__ptr->_next);

    free(__ptr);
}

inline NodeData_t getInput(const char* __str)
{
    printf("%s", __str);

    NodeData_t value;

    scanf_s(FORMAT_SPECIFIER, &value);

    return value;
}

inline void deleteFrontNode(LLPtr __obj)
{
    if(!__obj->_head) return;

    else if(__obj->_head == __obj->_tail)
    {
        free(__obj->_head);
        __obj->_head = __obj->_tail = NULL;
        __obj->_len = 0;
    }
    else
    {
        NodePtr temp = __obj->_head;
        __obj->_head = __obj->_head->_next;
        --__obj->_len;
        free(temp);
    }
}

inline void deleteBackNode(LLPtr __obj)
{
    if(!__obj->_head) return;

    else if(__obj->_head == __obj->_tail)
    {
        free(__obj->_head);
        __obj->_head = __obj->_tail = NULL;
        __obj->_len = 0;
    }
    else
    {
        NodePtr iterator = __obj->_head;

        while(iterator->_next != __obj->_tail) iterator = iterator->_next;

        free(iterator->_next);

        __obj->_tail = iterator;

        iterator->_next = NULL;

        --__obj->_len;
    }
}

inline void destroyLinkedList(LLPtr __obj)
{
    if( ! __obj->_head ) return;

    Utility_destroyRecursively(__obj->_head);

    __obj->_head = __obj->_tail = NULL;

    __obj->_len = 0;
}

inline struct LinkedList makeLinkedList()
{
    struct LinkedList obj = {0};

    return obj;
}

inline void printLinkedList(LLPtr __obj)
{

    if(!__obj->_head) {
        printf("[ ]");
        return;
    }

    printf("[ ");

    NodePtr iterator = __obj->_head;

    while(iterator->_next)
    {
        printf(FORMAT_SPECIFIER ", ", iterator->_data);
        iterator = iterator->_next;
    }

    printf( FORMAT_SPECIFIER " ]", iterator->_data);

}

inline void pushBackNode(LLPtr __obj, NodeData_t __value)
{
    NodePtr temp = (NodePtr) malloc(SIZEOF_NODE);

    if( ! temp ) 
    {
        errno = ENOMEM;
        return;
    }

    temp->_data = __value;
    temp->_next = NULL;

    if ( ! __obj->_head )
    {
        __obj->_head = __obj->_tail = temp;
    }
    else
    {
        __obj->_tail->_next = temp;
        __obj->_tail = temp;
    }

    ++__obj->_len;

}

inline void pushFrontNode(LLPtr __obj , NodeData_t __value)
{
    NodePtr temp = (NodePtr) malloc(SIZEOF_NODE);

    if( ! temp )
    {
        errno = ENOMEM;
        return;
    }

    temp->_next = __obj->_head;

    temp->_data = __value;

    __obj->_head = temp;

    if(!__obj->_head->_next)
    {
        __obj->_tail = __obj->_head;
    }

    ++__obj->_len;
}

inline void peekLinkedList(LLPtr __obj)
{
    printf("\n |+| ");
    if( ! __obj->_head )
    {
        printf("Head= NULL\tTail= NULL\tLen= 0");
        return;
    }
    
    printf("Head= " FORMAT_SPECIFIER "\t Tail= " FORMAT_SPECIFIER "\t Len= %llu" , (__obj->_head->_data) , ( __obj->_tail->_data) , __obj->_len );
}

int main(void)
{
    struct LinkedList obj = makeLinkedList();

    unsigned short int choice;

    while ( 1 )
    {
        printf(
            "\n 1. Push back"
            "\n 2. Push front"
            "\n 3. Delete back"
            "\n 4. Delete front"
            "\n 5. Destroy"
            "\n 6. Print"
            "\n 7. Peek\n\t->_"
        );

        scanf_s("%hu", &choice);

        switch(choice)
        {
            case 1 : pushBackNode(&obj , getInput("\n ==> Enter the value to push :- ")); break;
            
            case 2 : pushFrontNode(&obj , getInput("\n ==> Enter the value to push :- ")); break;

            case 3 : deleteBackNode(&obj); break;

            case 4 : deleteFrontNode(&obj) ; break;

            case 5 : destroyLinkedList(&obj) ; break;

            case 6 : printLinkedList(&obj) ; break;

            case 7 : peekLinkedList(&obj); break;

            default: printf("\n |=| Invalid choice!"); return 0;
        }

        printf("\n\t |+| Operation done Succesfully |+| \n");
    }

    destroyLinkedList(&obj);

    return 0;
}



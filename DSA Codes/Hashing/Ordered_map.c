#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

#define HMapValue_t int
#define HMapKey_t int
#define BUCKET_LENGTH (unsigned int)10

struct BaseNode
{
    HMapKey_t _key;
    HMapValue_t _value;
    struct BaseNode *_next;
};

typedef struct BaseNode Node;
typedef Node *NodePtr_t;
typedef unsigned long HmapLen_t;
typedef unsigned int (*HashFunction_t)(HMapKey_t);

typedef struct
{
    NodePtr_t _head;
    NodePtr_t _tail;
    HmapLen_t _len;

} LinkedList;

typedef struct
{
    LinkedList _bucket[BUCKET_LENGTH];

    HashFunction_t _hash_fnc;

} HashMap;

unsigned int hashFunctionHMap(HMapKey_t __value)
{
    return (__value < 0 ? (-__value) : __value) % BUCKET_LENGTH;
}

inline static HashMap initHMap()
{
    HashMap obj = {0};

    obj._hash_fnc = hashFunctionHMap;

    return obj;
}

inline static void insertHMap(HashMap *__obj, HMapKey_t __key, HMapValue_t __value)
{

    LinkedList *list = &( __obj->_bucket[ __obj->_hash_fnc(__key) ] );

    Node *new_node = (Node *)malloc(sizeof(Node));

    if (!new_node)
    {
        errno = ENOMEM;
        perror("Cannot insert element into HashMap");
        return;
    }

    new_node->_key = __key;
    new_node->_value = __value;
    new_node->_next = NULL;

    if (!list->_head)
    {
        list->_head = list->_tail = new_node;
    }
    else
    {
        if (__key >= list->_tail->_key)
        {
            list->_tail->_next = new_node;

            list->_tail = new_node;
        }
        else if (__key <= list->_head->_key)
        {
            new_node->_next = list->_head;

            list->_head = new_node;
        }
        else
        {
            NodePtr_t iterator = list->_head;

            while (iterator->_next && iterator->_next->_key < __key) iterator = iterator->_next;

            new_node->_next = iterator->_next;

            iterator->_next = new_node;
        }
    }

    ++list->_len;
}

inline bool deleteValueHMap(HashMap *__obj, HMapKey_t __key)
{
    LinkedList *bucket = &__obj->_bucket[__obj->_hash_fnc(__key)];

    if ( ! bucket->_head) return false;

    else if (bucket->_head->_key == __key)
    {
        if (bucket->_head == bucket->_tail)
        {
            free(bucket->_head);

            bucket->_head = bucket->_tail = NULL;
        }
        else
        {
            NodePtr_t temp = bucket->_head->_next;

            free(bucket->_head);

            bucket->_head = temp;
        }
    }
    else
    {
        NodePtr_t iterator = bucket->_head;

        while (iterator->_next && iterator->_next->_key < __key) iterator = iterator->_next;

        if ( ! iterator->_next) return false;

        else if ( iterator->_next == bucket->_tail)
        {
            free( bucket->_tail );

            iterator->_next = NULL;

            bucket->_tail = iterator;
        }
        else 
        {
            NodePtr_t temp = iterator->_next->_next;

            free( iterator->_next );

            iterator->_next = temp;
        }
    }

    -- bucket->_len;

    return true;
}

inline void destroyListHMap(NodePtr_t __ptr)
{
    if (__ptr)
    {
        destroyListHMap(__ptr->_next);
        free(__ptr);
    }
}

inline static void destroyHMap(HashMap *__obj)
{
    LinkedList *bucket_iterator = __obj->_bucket;
    const LinkedList *const bucket_end = bucket_iterator + BUCKET_LENGTH;

    while (bucket_iterator < bucket_end)
    {
        destroyListHMap(bucket_iterator->_head);

        bucket_iterator->_head = bucket_iterator->_tail = NULL;

        bucket_iterator->_len = 0;

        ++bucket_iterator;
    }
}

inline static NodePtr_t searchInHMap(HashMap *__obj, HMapKey_t __key)
{
    NodePtr_t bucket_iterator = (__obj->_bucket + hashFunctionHMap(__key))->_head;

    while (bucket_iterator)
    {
        if (bucket_iterator->_key == __key) break;

        else if (bucket_iterator->_key > __key) return NULL;

        bucket_iterator = bucket_iterator->_next;
    }

    return bucket_iterator;
}

inline static void printHMap(HashMap *__obj)
{
    LinkedList *bucket_iterator = __obj->_bucket;

    const LinkedList *const bucket_end = bucket_iterator + BUCKET_LENGTH;

    unsigned int index = 0;

    while (bucket_iterator < bucket_end)
    {
        NodePtr_t node_iterator = bucket_iterator->_head;

        printf("\n |%u| --- [ ", index);

        while (node_iterator)
        {
            printf(" [ %d,%d ] ", node_iterator->_key, node_iterator->_value);

            node_iterator = node_iterator->_next;
        }

        printf(" ]");

        ++bucket_iterator;

        ++index;
    }
}

int main(void)
{

    HashMap map = initHMap();

    for (int i = 20; i >= -10; --i) insertHMap(&map, i, i);

    printHMap(&map);

    if (deleteValueHMap(&map , 20)) puts("\n Value deleted");
    else puts("\nValue Not found");

    printHMap(&map);

    if (deleteValueHMap(&map , 100)) puts("\n Value deleted!");
    else puts("\n Value not found!");

    destroyHMap(&map);

    return 0;
}
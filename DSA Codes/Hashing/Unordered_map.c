#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define NodeValue_t     int
#define NodeKey_t       int
#define BUCKET_LENGTH   (unsigned short int)10

struct BaseNode
{
    NodeKey_t _key;
    NodeValue_t _value;
    struct BaseNode *_next;
};

typedef struct BaseNode Node;
typedef Node *NodePtr_t;
typedef unsigned long (*UMapHashFnc) ( NodeValue_t );

typedef struct
{
    NodePtr_t _head;
    NodePtr_t _tail;
    unsigned long _len;

} LinkedList;

typedef struct
{
    LinkedList _bucket[BUCKET_LENGTH];
    UMapHashFnc _hash_function;
} UMap;

typedef UMap *UMapPtr_t;

static void utilDestroyNodeUMap( NodePtr_t __node )
{
    if (  __node )
    {
        utilDestroyNodeUMap( __node->_next );

        free( __node );
    }
}

inline static void destroyUMap( UMapPtr_t __obj )
{
    for ( unsigned long i = 0 ; i < BUCKET_LENGTH ; ++i )
    {
        utilDestroyNodeUMap( __obj->_bucket[ i ]._head );

        __obj->_bucket[i]._head = __obj->_bucket[i]._tail = NULL;

        __obj->_bucket[i]._len = 0;
    }
}

unsigned long hashFuncUMap(NodeKey_t __key)
{
    return (__key < 0 ? -__key : __key) % BUCKET_LENGTH;
}

inline static UMap initUMap()
{
    UMap obj = {0};

    obj._hash_function = hashFuncUMap;

    return obj;
}

inline static void insertUMap(UMapPtr_t __obj , NodeKey_t __key , NodeValue_t __value)
{
    LinkedList *list = &__obj->_bucket[ __obj->_hash_function(__key) ];

    NodePtr_t new_node = (NodePtr_t) malloc ( sizeof(Node) );

    if ( ! new_node)
    {
        errno = ENOMEM;

        perror("Cannot generate new node");

        return;
    }

    new_node->_key = __key;
    new_node->_value = __value;
    new_node->_next = NULL;

    if (list->_head)
    {
        list->_tail->_next = new_node;
        list->_tail = new_node;
    }
    else list->_head = list->_tail = new_node;

    ++list->_len;
}

inline static _Bool deleteUMap(UMapPtr_t __obj, NodeKey_t __key )
{
    LinkedList *list = &__obj->_bucket[__obj->_hash_function(__key)];

    if ( ! list->_head ) return (_Bool) 0;

    else if ( list->_head->_key == __key )
    {
        NodePtr_t temp = list->_head;

        if ( list->_head == list->_tail ) list->_head = list->_tail = NULL;

        else list->_head = list->_head->_next;

        free(temp);
    }

    else
    {
        NodePtr_t iterator = list->_head;

        while ( iterator->_next )
        {
            if ( iterator->_next->_key == __key) break;

            iterator = iterator->_next;
        }

        if ( ! iterator->_next ) return (_Bool) 0;

        else if ( iterator->_next == list->_tail)
        {
            free ( list->_tail );

            iterator->_next = NULL;
        }

        else 
        {
            NodePtr_t temp = iterator->_next;

            iterator->_next = iterator->_next->_next;

            free ( temp );
        }
    }

    -- list->_len ;

    return (_Bool)1;
}

inline static void printlnUMap(UMapPtr_t __obj)
{
    for (unsigned int i = 0; i < BUCKET_LENGTH; ++i)
    {
        printf("\n |%u| -- [ ",i);

        NodePtr_t iterator = __obj->_bucket[i]._head;

        while (iterator)
        {
            printf(" (%d | %d) ", iterator->_key , iterator->_value);

            iterator = iterator->_next;
        }

        printf(" ]");
    }
}

inline static NodePtr_t searchUMap ( UMapPtr_t __obj , NodeKey_t __key)
{
    NodePtr_t iterator = __obj->_bucket[ __obj->_hash_function ( __key ) ]._head;

    while ( iterator )
    {
        if ( iterator->_key == __key ) return iterator;

        iterator = iterator->_next;
    }

    return NULL;
}

int main(void)
{
    UMap map = initUMap();

    for( NodeValue_t i = -20 ; i < 20 ; ++i) insertUMap(&map, i , i);

    printlnUMap( &map );

    NodePtr_t temp = searchUMap( &map , 15);

    if ( temp) puts("Value found");
    else puts("\nvalue not found!");

    temp = searchUMap( &map , 100);
    
    if ( temp) puts("Value found");
    else puts("value not found!");

    destroyUMap( &map );

    return 0;
}
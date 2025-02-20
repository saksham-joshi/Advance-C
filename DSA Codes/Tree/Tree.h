#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define TRUE (_Bool)1
#define FALSE (_Bool)0
#define NodeData_t int
#define IS_NODE_DATA_PRINTABLE 1

#if IS_NODE_DATA_PRINTABLE
    #if defined(NodeData_t)
            #if NodeData_t == int
                #define FORMAT_SPECIFIER_TREE "%d"
            #elif NodeData_t == unsigned int
                #define FORMAT_SPECIFIER_TREE "%u"
            #elif NodeData_t == short int
                #define FORMAT_SPECIFIER_TREE "%hd"
            #elif NodeData_t == unsigned short int
                #define FORMAT_SPECIFIER_TREE "%hu"
            #elif NodeData_t == long
                #define FORMAT_SPECIFIER_TREE "%ld"
            #elif NodeData_t == long long
                #define FORMAT_SPECIFIER_TREE "%lld"
            #elif NodeData_t == unsigned long long
                #define FORMAT_SPECIFIER_TREE "%llu"
            #elif NodeData_t == char
                #define FORMAT_SPECIFIER_TREE "%c"
            #elif NodeData_t == float
                #define FORMAT_SPECIFIER_TREE "%f"
            #elif NodeData_t == long float
                #define FORMAT_SPECIFIER_TREE "%lf"
            #elif NodeData_t == double
                #define FORMAT_SPECIFIER_TREE "%lf"
            #elif NodeData_t == long double
                #define FORMAT_SPECIFIER_TREE "%Lf"
            #else
                #define FORMAT_SPECIFIER_TREE "%s"
            #endif

    #else   
        #error "You have to define 'NodeData_t to work on any Linked List!"
    #endif
#endif

struct BaseNode 
{
    struct BaseNode* _left;
    NodeData_t _data;
    struct BaseNode* _right;
};

typedef struct
{
    struct BaseNode* _root;

} BinaryTree;

typedef struct BaseNode Node;
typedef Node* NodePtr_t;



#if IS_NODE_DATA_PRINTABLE

    static void inOrderPrint ( NodePtr_t __node )
    {
        if ( __node )
        {
            inOrderPrint( __node->_left );

            printf(" " FORMAT_SPECIFIER_TREE " ", __node->_data );

            inOrderPrint( __node->_right);
        }
    }

    static void preOrderPrint ( NodePtr_t __node )
    {
        if ( __node )
        {
            printf(" " FORMAT_SPECIFIER_TREE " ", __node->_data );

            preOrderPrint( __node->_left );

            preOrderPrint( __node->_right);
        }
    }

    static void postOrderPrint ( NodePtr_t __node )
    {
        if ( __node )
        {
            postOrderPrint( __node->_left );
            
            postOrderPrint( __node->_right);

            printf(" " FORMAT_SPECIFIER_TREE " ", __node->_data );
        }
    }

#endif

#ifdef FORMAT_SPECIFIER_TREE
    inline static NodeData_t getInput( const char* __message )
    {
        NodeData_t value;

        printf_s(__message);
        scanf_s(FORMAT_SPECIFIER_TREE , &value);
        
        return value;
    }
#endif

inline static NodePtr_t generateNode ( NodeData_t __data )
{
    NodePtr_t ptr = ( NodePtr_t ) malloc ( sizeof ( Node ) );

    if ( ptr )
    {
        ptr->_left = ptr->_right = NULL;
        ptr->_data = __data;
    }
    else
    {
        errno = ENOMEM;
        perror("Cannot generate node");
    }

    return ptr;
}

static void destroyTree ( NodePtr_t __node )
{
    if ( __node )
    {
        destroyTree( __node->_left);
        destroyTree( __node->_right );
        free( __node );
    }
}

static unsigned int heightOfTree( NodePtr_t __node )
{
    if ( __node )
    {
        unsigned int height_left = heightOfTree( __node->_left );
        unsigned int height_right = heightOfTree( __node-> _right );

        return 1 + ( height_left > height_right  ? height_left : height_right);
    }

    return 0;
}

inline static _Bool isLeafNode ( NodePtr_t __node )
{
    return !__node->_left && !__node->_right;
}
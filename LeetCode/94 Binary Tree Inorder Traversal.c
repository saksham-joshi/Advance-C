/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define BaseVector_t int 
#define VectorLen_t unsigned long

typedef struct 
{
    BaseVector_t* _array;
    VectorLen_t _len;
    VectorLen_t _allocated;
} Vector ;

typedef Vector* VectorPtr_t;

inline static Vector vectorInit( VectorLen_t __allocate )
{
    Vector obj = { 0 };

    obj._array = ( BaseVector_t *) calloc ( __allocate , sizeof ( BaseVector_t ) );

    obj._allocated = __allocate;

    return obj;
}

inline static void vectorPushBack( VectorPtr_t __vector , BaseVector_t __value )
{
    if ( __vector->_len == __vector->_allocated )
    {
        BaseVector_t* old_ar_iterator = __vector->_array;

        BaseVector_t* new_array = ( BaseVector_t * ) calloc ( __vector->_allocated * 2, sizeof ( BaseVector_t ) );

        BaseVector_t* new_arr_iterator = new_array;

        for ( VectorLen_t i = 0 ; i < __vector->_len ; ++i , ++old_ar_iterator , ++new_arr_iterator ) *new_arr_iterator = *old_ar_iterator;

        free ( __vector->_array );

        __vector->_array = new_array;

        __vector->_allocated *= 2;
    }

    __vector->_array [ __vector->_len++ ] = __value;

}

static void inOrder ( VectorPtr_t __vector , struct TreeNode* __node)
{
    if ( __node )
    {
        inOrder ( __vector , __node->left );
        vectorPushBack ( __vector , __node->val );
        inOrder ( __vector , __node->right );
    }
}
inline static int* inorderTraversal(struct TreeNode* __root, int* __return_size)
{
    Vector vec = vectorInit( 8 );

    inOrder ( &vec , __root);

    *__return_size = vec._len;

    return vec._array;
}
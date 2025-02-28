
// If you want to change the type of the vector,
// then you have to change type here |            
#define BaseVector_t int   // <------|
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


/*|====[ A Sample code of how to use SimpleString ]====|*/

int main ( void )
{
    // You can pre-allocate the memory at vector
    Vector vec = vectorInit(8);

    // inserting new value to the vector
    vectorPushBack(&vec , 91);

}
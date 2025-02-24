#include<stdlib.h>
#include<errno.h>


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

    if ( obj._array ) obj._allocated = __allocate;

    else errno = ENOMEM;

    return obj;
}

inline static void vectorPushBack( VectorPtr_t __vector , BaseVector_t __value )
{
    if ( __vector->_len == __vector->_allocated )
    {
        BaseVector_t* old_ar_iterator = __vector->_array;

        BaseVector_t* new_array = ( BaseVector_t * ) calloc ( __vector->_allocated * 2, sizeof ( BaseVector_t ) );

        if ( ! new_array ) { errno = ENOMEM; return; }

        BaseVector_t* new_arr_iterator = new_array;

        for ( VectorLen_t i = 0 ; i < __vector->_len ; ++i , ++old_ar_iterator , ++new_arr_iterator ) *new_arr_iterator = *old_ar_iterator;

        free ( __vector->_array );

        __vector->_array = new_array;

        __vector->_allocated *= 2;
    }

    __vector->_array [ __vector->_len++ ] = __value;

}

inline static void vectorPopBack ( VectorPtr_t __vector )
{
    if ( __vector->_len ) -- __vector->_len;

    else errno = ENOMEM;
}

inline static void vectorDestroy ( VectorPtr_t __vector )
{
    if ( __vector->_array )
    {
        free ( __vector->_array );

        __vector->_array = NULL;

        __vector->_allocated = __vector->_len = 0 ;
    }
}

inline static BaseVector_t* vectorBack ( VectorPtr_t __vector )
{
    if ( __vector->_len ) return &__vector->_array[ __vector->_len - 1];

    errno = EPERM;

    return NULL;
}

inline static BaseVector_t* vectorFront ( VectorPtr_t __vector )
{
    if ( __vector->_len ) return __vector->_array;

    errno = EPERM;

    return NULL;
}

inline static VectorLen_t vectorLen ( VectorPtr_t __vector )
{
    return __vector->_len;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
int vectorCmp ( void* __context , const void* __lhs , const void* __rhs )
{
    return *((BaseVector_t*) __lhs) - *( (BaseVector_t*) __rhs);
}
#pragma clang diagnostic pop

inline static void vectorSort ( VectorPtr_t __vector )
{
    qsort_s( __vector->_array , __vector->_len , sizeof ( BaseVector_t ) , vectorCmp , NULL);
}
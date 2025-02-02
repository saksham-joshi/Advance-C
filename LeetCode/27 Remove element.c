inline static int removeElement(int* __array , unsigned int __len , int __val)
{
    int* writer = __array;

    int* iterator = __array;

    const int*const end = __array + __len;

    for ( ; iterator != end ; ++iterator) if ( *iterator != __val) *writer++ = *iterator;

    return writer - __array;

}
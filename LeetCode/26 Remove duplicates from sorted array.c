inline static int* baseRemoveDuplicates(int* __array , const int*const __end)
{
    int *writer = __array++;

    for( ; __array < __end ; ++__array)
    {
        if (*writer != *__array)
        {
            ++writer;
            *writer = *__array;
        }
    }

    return ++writer;
}

inline static int removeDuplicates(int* __array, unsigned int __len)
{
    return baseRemoveDuplicates(__array , ( __array + __len )) - __array;
}
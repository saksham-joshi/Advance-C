inline static int singleNumber(int *__array, const unsigned int __len)
{
    const int*const end = __array + __len;

    int output = *__array++;

    while ( __array < end ) output ^= *__array++;

    return output;
}

/*
 The Below code is also a optimized solution but generates the time
 complexity of O ( n + nlogn).
*/
int intCmp(const void* __a , const void* __b)
{
    return *((int*) __a) - *((int*) __b);
}

inline static int singleNumber(int *__array, const unsigned int __len)
{
    if (__len == 1) return *__array;

    const int *const end = __array + __len - 1;

    qsort(__array, __len , sizeof(int), intCmp);

    while ( __array < end)
    {

        if (*__array != __array[1]) return *__array;

        const int*const start_point = __array + 1;

        while( __array <= end && *__array == *start_point) ++__array;
        
    }

    return *end;
}
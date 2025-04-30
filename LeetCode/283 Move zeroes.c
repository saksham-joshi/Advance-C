inline static void moveZeroes(int* __array, int __len)
{
    const int*const end_array = __array + __len;

    int *non_zero_writer = __array;

    while( __array < end_array )
    {
        if ( *__array )
        {
            *non_zero_writer = *__array;

            ++non_zero_writer;
        }

        ++__array;
    }

    while ( non_zero_writer < end_array )
    {
        *non_zero_writer = 0;

        ++non_zero_writer;
    }
}
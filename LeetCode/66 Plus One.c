/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
inline static int* copyArray(int* __array , unsigned short int __len , char __some_non_zero_value)
{
    int *ar = ( int *) calloc ( __len , sizeof(int) );

    int* iterator = ar;

    if ( __some_non_zero_value ) *iterator++ = __some_non_zero_value;

    for ( const int*const end = ar + __len ; iterator < end ;  ++ __array , ++iterator ) *iterator = *__array;
    
    return ar;
}


inline static int* plusOne(int* __digits, unsigned short int __len, int* __return_size)
{
    int* reverse_iterator = __digits + __len - 1;

    if ( *reverse_iterator != 9 )
    {
        ++ ( *reverse_iterator );

        *__return_size = __len;

        return copyArray(__digits, __len , '\0');
    }

    char carry = '\0';

    if (*reverse_iterator == 9 )
    {
        *reverse_iterator = 0;
        carry = 1;
        --reverse_iterator;
    }

    while ( reverse_iterator >= __digits )
    {
        if ( *reverse_iterator != 9)
        {
            *reverse_iterator += carry;

            *__return_size = __len;

            return copyArray(__digits , __len , '\0');
        }

        *reverse_iterator += carry;

        if (*reverse_iterator >= 10)
        {
            carry = (char)1;
            *reverse_iterator %= 10;
        }
        else carry = '\0';

        -- reverse_iterator;
    }

    *__return_size = __len;

    if (! carry) return __digits;

    return copyArray(__digits , ++(*__return_size) , carry);
}
inline static void shiftElement(const int* __shift_from, const int*const __end_point , int* __shift_to)
{
    while(__shift_from >= __end_point)
    {
        *__shift_to = *__shift_from;
        -- __shift_from;
        -- __shift_to;
    }
}

/*
 @param __nums1          :  this array contains all the elements and is trailed by zero where the elements of other array will be inserted
 @param __nums1len       :  contains the complete length of __nums1
 @param __m              :  contains the length of __nums1 excluding trailing zeros
 @param __nums2          :  this array contains elements which will be moved to __nums1
 @param __num2len, __n   :  contains the complete length of __nums1
*/
inline static void merge(int* __nums1, int __nums1len, int __m, int* __nums2, int __nums2len, int __n)
{
    const int *rev_iterator_nums1 = __nums1 + __m - 1;
    const int *rev_iterator_nums2 = __nums2 + __n - 1;

    int *write_iterator = __nums1 + __nums1len - 1;

    while ( (rev_iterator_nums1 >= __nums1) && (rev_iterator_nums2 >= __nums2))
    {
        if (*rev_iterator_nums1 > *rev_iterator_nums2)
        {
            *write_iterator = *rev_iterator_nums1;
            --rev_iterator_nums1;
        }
        else
        {
            *write_iterator = *rev_iterator_nums2;
            --rev_iterator_nums2;
        }

        --write_iterator;
    }

    if (rev_iterator_nums1 >= __nums1) shiftElement(rev_iterator_nums1, __nums1, write_iterator);
    
    else if (rev_iterator_nums2 >= __nums2) shiftElement(rev_iterator_nums2 , __nums2 , write_iterator);
}
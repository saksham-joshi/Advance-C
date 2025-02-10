/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int* _array;
    int* _write_pos;
    int *_end_write_pos;

} ShortArray;

inline static void pushBackShortArray( ShortArray* __array , int __value )
{
    *(__array->_write_pos) = *(__array->_end_write_pos) = __value;

    ++ __array->_write_pos;
    -- __array->_end_write_pos;
}

inline static ShortArray initShortArray( unsigned short int __len )
{
    ShortArray array = { 0 };

    array._array = (int*) calloc ( __len , sizeof(int) );

    array._write_pos = array._array;
    array._end_write_pos = array._array + __len - 1;

    (*array._write_pos) = *(array._end_write_pos) = 1;

    ++ array._write_pos;
    -- array._end_write_pos;

    return array;
}

inline static int formula( long long __prev_value, long long __row_no , long long __col_no)
{
    return (__prev_value * __row_no) / __col_no;
}

inline static int* getRow(const int __row_index, int* __return_size)
{

    *__return_size = __row_index + 1;

    ShortArray output = initShortArray( *__return_size );

    if (__row_index < 2) return output._array;

    for(int rev_row_no = __row_index , col_no = 1  ; output._write_pos <= output._end_write_pos; ++ col_no , --rev_row_no)
    {
        pushBackShortArray(&output , formula( * (output._write_pos - 1) , rev_row_no , col_no));
    }
    
    return output._array;   
}
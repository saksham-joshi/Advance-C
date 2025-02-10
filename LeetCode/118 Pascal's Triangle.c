/*
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 typedef struct
 {
     int* _array;
     unsigned short int _len;
     int* _write_pos;
 
 } ShortArray;
 
 inline static void pushBackShortArray( ShortArray* __array , int __value )
 {
     *(__array->_write_pos) = __value;
 
     ++ __array->_write_pos;
 }
 
 inline static ShortArray initShortArray( unsigned short int __len )
 {
     ShortArray array = { 0 , __len - 1 , 0 };
 
     array._array = (int*) calloc ( __len , sizeof(int) );
 
     array._write_pos = array._array;
 
     (*array._write_pos) = *(array._array + __len - 1) = 1;
 
     ++ array._write_pos;
 
     return array;
 }
 
 
 inline static int** generate(int __numRows, int* __returnSize, int** __returnColumnSizes)
 {
     int** output = (int**) calloc ( __numRows , sizeof(int*) );
     
     *__returnColumnSizes = (int*) calloc ( __numRows , sizeof(int) );
 
     int *iterator_columnsize = *__returnColumnSizes;
 
     int** iterator_output = output;
 
     for(int i = 1 ; i <= __numRows ; ++i , ++iterator_output , ++(iterator_columnsize))
     {
         ShortArray obj = initShortArray( i ); 
 
         int* prev = (i > 1) ? *(iterator_output - 1) : NULL;
 
         for ( unsigned short int j = 1; j < obj._len ;  ++j)
         {
             pushBackShortArray( &obj , prev[j] + prev[j-1]);
         }
 
         *iterator_columnsize = i;
 
         *iterator_output = obj._array;
 
     }
 
     * __returnSize = __numRows;
 
     return output;
 }
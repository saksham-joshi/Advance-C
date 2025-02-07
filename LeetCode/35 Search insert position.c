static int binarySearch(int *__left , int* __right , const int*const __source , const int __target)
{
    if (__left == __right && *__left != __target)
    {
        return ( __left + ( *__left < __target ?  1 : -1 ) ) - __source;
    }
    else if ( __left == __right && *__left == __target)
    {
        return __left - __source;
    }
    else if( __left == __right - 1)
    {
        if (*__left < __target && *__right > __target) return __right - __source;
        
        else if (*__left <= __target) return  __left - __source;

        else if ( *__right >= __target) return __right - __source;
        
    }
    
    int* mid_value =  __left + ( ( __right - __left ) / 2 ) ;

    if( *mid_value == __target ) return mid_value - __source;

    else if ( *mid_value < __target ) return binarySearch(mid_value , __right , __source , __target);

    return binarySearch(__left , mid_value , __source , __target);
}

int searchInsert(int* __array, int __len, int __target)
{
    if ( *__array >= __target ) return 0;

    int* right = ( __array + __len - 1);
    
    if ( __target > *right) return __len;

    else if ( __target == *right ) return --__len ;

    return binarySearch(__array , right , __array , __target);
}
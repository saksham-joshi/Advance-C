int intCmp (const void* __lhs , const void* __rhs)
{
    return *((int*) __lhs) - *((int*) __rhs);
}

inline static bool containsDuplicate(int* __array, unsigned int __len)
{
    
    qsort( __array , __len-- , sizeof(int) , intCmp);

    for( unsigned int i = 0 ; i < __len ; ++i )  if (*__array == *++__array) return true;
    
    return false;
}
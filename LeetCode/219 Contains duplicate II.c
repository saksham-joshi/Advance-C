inline static bool containsNearbyDuplicate(int* __array, unsigned short int __len , const unsigned short int __k)
{
    if ( ! __k || __len == 1) return false;

    for(unsigned short int i = 0 ; i < __len ; ++i , ++__array)
    {
        const int* iterator = __array + 1;

        for(unsigned short int j = i + 1 ; j < __len && j <= (i + __k) ; ++j , ++iterator) if (*__array == *iterator) return true;
        
        if ( __len > 400) i = i + __k; 
    }

    return false;
}
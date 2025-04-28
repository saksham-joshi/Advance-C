inline static int sumToN( unsigned int __n )
{
    return (__n * (__n + 1) ) / 2;
}

inline static int missingNumber(int* __array, const unsigned short int __len)
{
    int* iterator = __array;

    int sum = *iterator;

    int smallest = *iterator, largest = *iterator;

    ++iterator;

    for(unsigned short int i = 1; i < __len; ++i , ++iterator)
    {
        sum += *iterator;

        if( *iterator < smallest ) smallest = *iterator;

        else if( *iterator > largest ) largest = *iterator;
    }

    int output = sumToN(largest) - (sumToN( smallest) - smallest) - sum;

    if ( output == 0 && smallest == 0) return largest + 1; 
    
    else if ( output == 0 ) return smallest - 1;

    return ( output < 0 ) ? -output : output;
}
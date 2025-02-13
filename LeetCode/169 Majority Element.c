inline static int majorityElement(int* __array, unsigned short int __len)
{
    int candidate;
    unsigned short int count = 0;

    for(unsigned short int i = 0 ; i < __len ; ++i , ++__array)
    {
        if ( ! count )
        {
            candidate = *__array;
            count = 1;
        }
        else if ( candidate == *__array ) ++count;

        else if ( candidate != *__array ) --count;
    }

    return candidate;
}
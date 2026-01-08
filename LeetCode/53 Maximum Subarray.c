inline static int maxSubArray(const int* __array, const int __len)
{
    int sum = *__array;

    int output = sum;

    const int* it = __array + 1;

    const int*const end = __array + __len;
    
    while(it < end)
    {
        sum += *it;

        if(*it > sum) sum = *it;

        if(sum > output) output = sum;

        if(sum < 0) sum = 0;

        ++it;
    }

    return output;
}
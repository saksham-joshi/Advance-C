// Time taken- 0ms

typedef struct
{
    int _num;
    int _index;

} ValueIndex;


int intCompare(const void* __a ,const void* __b)
{
    return ((ValueIndex*) __a)->_num - ((ValueIndex*) __b)->_num;
}


inline static void fillDummyArray(int* __original_array , ValueIndex* __dummy , int __len)
{
    for(int i = 0 ; i < __len ; ++i , ++__original_array , ++__dummy)
    {
        __dummy->_index = i;
        __dummy->_num = *__original_array;
    }
}

inline static int* twoSum(int* __nums, int __numsSize, int __target, int* __returnSize)
{
    ValueIndex dummy[__numsSize];

    fillDummyArray(__nums , dummy , __numsSize);
    
    qsort(dummy , __numsSize , sizeof(ValueIndex) , intCompare);

    *__returnSize = 0;

    int* output = NULL;

    ValueIndex* start_ptr = dummy;
    ValueIndex* end_ptr = dummy + __numsSize;

    while (start_ptr < end_ptr )
    {
        ValueIndex key = { __target - start_ptr->_num , 0 };
        
        ValueIndex* temp = (ValueIndex*) bsearch(&key , dummy, __numsSize , sizeof(ValueIndex), intCompare);

        if( temp && temp != start_ptr )
        {
            *__returnSize = 2;

            output = (int*) calloc ( 2, sizeof(int));
            output[0] = start_ptr->_index < temp->_index ? start_ptr->_index : temp->_index ;
            output[1] = output[0] == start_ptr->_index ? temp->_index : start_ptr->_index;

            *__returnSize = 2;

            return output;
        }

        ++start_ptr;
    }

    return output;
}
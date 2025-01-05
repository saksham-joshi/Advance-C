#include<stdio.h>
#include<time.h>

inline long long squareSum(long long __num)
{
    long long square_sum = 0;

    while(__num != 0)
    {
        int temp = __num % 10;
        square_sum += (temp * temp);
        __num /= 10;
    }

    return square_sum;
}
inline int isHappyNumber(long long __num, unsigned short int __max_recursive_length)
{
    if(!__max_recursive_length) return 0;
    
    long long square_sum = squareSum(__num);

    if(square_sum == 1) return 1;
    else if(square_sum == 0) return 0;
    
    return isHappyNumber(square_sum, --__max_recursive_length);
     
}

int main(void)
{
    long long count = 0;

    for(long long int i = 0 ; i < 100000 ; ++i)
    {
        if(isHappyNumber(i, 40)){
            printf("%lld | ", i);
            ++ count;
        }
    }

    printf("\n\n |+| Time taken : %.5f sec to find '%lld' happy numbers.", (float) clock() / (float)CLOCKS_PER_SEC , count);
    
    return 0;
}
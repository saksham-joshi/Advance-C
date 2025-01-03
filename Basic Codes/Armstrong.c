#include<stdio.h>
#include<time.h>

typedef long long Int;
typedef unsigned short SmallInt;

inline static SmallInt numLen(Int __num)
{
    if (__num == 0) return 1;

    SmallInt count = 0;
    while(__num != 0){
        __num /= 10;
        ++count;
    }
    return count;
}

inline static Int toPower(Int __num , SmallInt __pow)
{
    Int output = 1;

    while(__pow){
        output*=__num;
        --__pow;
    }

    return output;
}

inline static SmallInt armStrong(Int __num)
{
    SmallInt len = numLen(__num);

    Int original = __num = (__num < 0 ? - __num : __num);

    Int arm = 0;

    while (__num != 0){
        arm += toPower(__num%10, len);
        __num /= 10;
    }

    return arm == original;
}

int main(){

    puts("\n | Here are the armstrong numbers between 0 to 100000 :");

    for(Int i = 0 ; i < 1000000 ; ++i){
        if(armStrong(i)){
            printf(" %lld ", i);
        }
    }

    printf("\n Time Taken = %.5lf sec.", (double) clock()/ (double)CLOCKS_PER_SEC);

    return 0;
}
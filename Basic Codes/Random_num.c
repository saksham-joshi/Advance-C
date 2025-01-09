#include<stdlib.h>
#include<time.h>
#include<float.h>
#include<stdio.h>
#include<math.h>

inline static void swapLongLong(long long* __1 , long long* __2)
{
    long long temp = *__1;
    *__1 = *__2;
    *__2 = temp;
}

inline static void swapFloat(float* __1 , float* __2)
{
    float temp = *__1;
    *__1 = *__2;
    *__2 = temp;
}

inline static void generateSeed()
{
    srand(time(NULL));
}

inline static long long generateRandomLongLong()
{
    generateSeed();
    return ((LLONG_MAX - (long long) rand())/ (long long)rand());
}

inline static float generateRandomFloat()
{
    generateSeed();
    return (FLT_MAX - (float)rand()) / ((float) rand());
}

inline static long long generateRandomLongLongRange(long long __start , long long __end)
{
    if (__start == __end) return __start;
    if(__start > __end) swapLongLong(&__start , &__end);

    return (generateRandomLongLong() % (__end - __start) ) + __start;
}

inline static float generateRandomFloatRange(float __start , float __end)
{

    if (__start == __end) return __start;
    if(__start > __end) swapFloat(&__start , &__end);

    return (fmod(generateRandomFloat(), (__end - __start)) + __start);
}

int main(void)
{
    printf("%lld\n%.3f", generateRandomLongLongRange(100,120) , generateRandomFloatRange(100,120));
}
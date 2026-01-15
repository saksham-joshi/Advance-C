inline static void swap(int *__a , int *__b)
{
    int temp = *__a;
    *__a = *__b;
    *__b = temp;
}

inline static int uniquePaths(int __row, int __col)
{
    if(__row == 1 || __col == 1) return 1;

    else if(__row < __col) swap(&__row, &__col);

    long long output = 1;
    int j = 1;

    int total = __row + __col - 2;

    for(int i = __row; i <= total; ++i, ++j)
    {
        output *= i;
        output /= j;
    }

    return output;
}
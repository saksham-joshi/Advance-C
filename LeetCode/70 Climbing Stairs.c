// contains true if series is not generated otherwise false
bool SERIES_GENERATED__ = true;
int FIBONACCI_SERIES__[46] = {0};

inline static void generateFibonacciSeries()
{
    unsigned int first = 1;
    unsigned int second = 1;

    for(unsigned int i = 0 ; i < (sizeof(FIBONACCI_SERIES__)/sizeof(int) - 1) ; ++i)
    {
        FIBONACCI_SERIES__[i] = first;
        FIBONACCI_SERIES__[++i] = second;

        first += second;
        second += first;
    }

    SERIES_GENERATED__ = false;
}

inline static int climbStairs(int __num)
{
    if (SERIES_GENERATED__) generateFibonacciSeries();

    return FIBONACCI_SERIES__ [ __num ];
}
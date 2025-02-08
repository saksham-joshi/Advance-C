#define sqr( __num ) ( __num * __num)

inline static int mySqrt(const unsigned int __num)
{
    if ( __num < 2) return __num;

    unsigned int lower_range = 0;
    unsigned int higher_range = __num;

    while (lower_range < higher_range - 1)
    {
        unsigned int mid_value = ( (unsigned long long) higher_range + (unsigned long long) lower_range ) / 2;

        unsigned long long square_of_mid_value = (unsigned long long) mid_value * (unsigned long long) mid_value;

        if ( square_of_mid_value == __num ) return mid_value;

        else if ( square_of_mid_value < __num) lower_range = mid_value;

        else higher_range = mid_value;
        
    }

    return lower_range;
}
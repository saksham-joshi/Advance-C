double powHelper(double __x, unsigned long long __n)
{
    double output = __x;
    unsigned long long i = 1;
    

    while(i * 2 <= __n)
    {
        output *= output;
        i *= 2;
    }
    
    if( i < __n) output *= powHelper(__x, __n - i);

    return output;
}

double myPow(double __x, int __n)
{
    if(__n == 0) return 1;
    
    else if(__x == 0) return 0;

    else if(__x == 1) return 1;

    else if( __n > 0) return powHelper(__x, __n);

    return 1.0/powHelper(__x, -(long long)__n);
}
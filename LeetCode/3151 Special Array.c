#define EVEN (char) 0
#define ODD (char) 1

inline static bool isEven(int __num)
{
    printf("\n =>> %d", __num);
    return (__num == 1 || __num % 2 != 0) ? false : true;
}

inline static bool isArraySpecial(int* __nums, int __len)
{
    char expected = 2;

    while  (__len--)
    {
        switch(expected)
        {
            case EVEN : 
                if (! isEven(*__nums)) return false;
                else expected = ODD;
                break;

            case ODD : 
                if (isEven(*__nums)) return false;
                else expected = EVEN;
                break;
            
            default : expected = (isEven(*__nums) ? ODD : EVEN);
        }

        ++__nums;
    }

    return true;
}
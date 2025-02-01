#define MAX_ROMAN_LEN 18

typedef struct
{
    int _num;
    unsigned int _len;
} 
  NumStore ;


inline static char romanAsPerLen(int __len)
{
    switch(__len)
    {
        case 1 : return 'I';

        case 2 : return 'X';

        case 3 : return 'C';

        case 4 : return 'M';
    }

    return '\0';
}



inline static NumStore intReverse(int __num)
{
    NumStore obj = {0};

    while ( __num )
    {
        obj._num = ( obj._num * 10) + ( __num % 10 );
        __num /= 10;
        ++ obj._len;
    }

    return obj;
}


inline static void writeChar(char** __str, const char __ch)
{
    **__str = __ch;
    ++ *__str;
}


inline static void writeContinous(char** __str, const char __ch, unsigned int __count)
{
    while ( __count-- ) 
    {
        **__str = __ch;
        ++ *__str;
    }
}


inline static void baseInt2Roman( char** __output_string , const int __digit , const char __one, const char __five, const char __ten )
{
    if ( __digit == 9 )
    {
        writeChar(__output_string , __one);
        writeChar(__output_string , __ten);
    }
    else if ( __digit == 4 )
    {
        writeChar(__output_string , __one);
        writeChar(__output_string , __five); 
    }
    else if ( __digit == 5 )
    {
        writeChar( __output_string , __five );
    }
    else if ( __digit > 5)
    {
        writeChar( __output_string , __five);
        writeContinous( __output_string , __one , __digit - 5);
    }
    else
    {
        writeContinous( __output_string , __one , __digit);
    }
}

inline static char* intToRoman(int __num)
{
    char* output = (char*) calloc ( MAX_ROMAN_LEN , sizeof(char));

    char* iterator = output;

    NumStore obj = intReverse( __num );

    while ( obj._num )
    {
        int digit = obj._num % 10;

        if ( digit )
        {
            switch(obj._len)
            {
                case 4 : writeContinous(&iterator, 'M', digit); break;

                case 3 : baseInt2Roman(&iterator, digit , 'C' , 'D' , 'M'); break;

                case 2 : baseInt2Roman(&iterator , digit , 'X' , 'L', 'C'); break;

                case 1 : baseInt2Roman(&iterator , digit , 'I' , 'V' , 'X'); break;

            }
        }

        -- obj._len;

        obj._num /= 10;

    }

    if ( obj._num && obj._len ) writeChar(&iterator , romanAsPerLen( obj._len ) );

    *iterator = '\0';

    return output;
}
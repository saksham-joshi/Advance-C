inline static int mapRomanToInt(char __ch)
{
    switch(__ch)
    {
        case 'I' : return 1;
        
        case 'V' : return 5;
        
        case 'X' : return 10;
        
        case 'L' : return 50; 
        
        case 'C' : return 100;
        
        case 'D' : return 500;
        
        case 'M' : return 1000;
    }
    
    return 0;
}

inline static int romanToInt(const char* __str)
{
    
    int output = 0;

    while ( *__str )
    {
        int cur_value = mapRomanToInt(*__str);
        int next_value = mapRomanToInt(*++__str);

        if(cur_value < next_value)
        {
            output += (next_value - cur_value);
            ++__str;
        }

        else output += cur_value;
        

    }

    return output;
}
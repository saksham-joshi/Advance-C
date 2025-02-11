inline static int maxProfit(int* __prices, const unsigned int __len)
{
    const int*const end = __prices + __len;

    int min_value = *__prices;
    int max_value = 0;
    int output = 0;
    int profit = 0;

    ++ __prices;

    while ( __prices != end )
    {
        if( *__prices < min_value ) 
        {
            min_value = *__prices;
            max_value = 0;
        }

        else if( *__prices > max_value) max_value = *__prices;

        profit = ( max_value > min_value) ? max_value - min_value : 0 ;

        if (output < profit ) output = profit;

        ++ __prices;

    }

    return output;
}
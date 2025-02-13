inline static int titleToNumber(const char* __column_title)
{
    int output = 0;

    while ( *__column_title )
    {
        output = (output * 26) + (*__column_title - 64);

        ++ __column_title;
    }

    return output;
}
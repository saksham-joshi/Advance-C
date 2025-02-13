inline static unsigned int reverseBits(uint32_t __value)
{
    uint32_t output = 0;

    char count = 32;

    while ( count-- )
    {
        output |= ( ( ( __value % 2 == 0 ) ? 0u : 1u ) << count);

        __value >>= 1;
    }

    return output;
}
#include<stdio.h>
#include<stdarg.h>

void printInt(int __count, ... )
{
    va_list arglist;

    va_start(arglist, __count);
    
    for(int i = 0 ; i < __count; ++i)
    {
        
        printf("| %d\t", va_arg(arglist, int)); 
    }

    va_end(arglist);

}

int main(void)
{
    printInt(9,  1,2,3,4,5,6,7,8,9);

    return 0;
}
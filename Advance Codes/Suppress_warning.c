
/*
    When you compile your code with "-Wall" or "-Wextra" or "-Wpedantic"
    flags then the compiler shows you the warning for even minute things
    which helps you to more optimize your code.

    However, sometimes these warnings are needed to be intentionally 
    suppressed so that a smooth and warning-free code can be built. 

    Suppressing of compiler warnings may not affect the runtime. It 
    only affects the developer mind during compilation. LoL
*/

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"

inline static void fnc ( )
{
    int a;
}

#pragma clang diagnostic pop

int main ( void )
{
    fnc();
}
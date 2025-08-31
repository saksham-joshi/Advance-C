
#if defined(__clang__)
    #define COMPILER "Clang"
#elif defined(__GNUC__)
    #define COMPILER "Gcc"
#else
    #error Cannot detect the compiler
#endif

#if defined(_M_X64) || defined(__X86_64__)
    #define CURRENT_ARCH "x86_64"
#elif defined(__i386__) || defined(_M_IX86)
    #define CURRENT_ARCH "X86"
#elif defined(__aarch64__) || defined(_M_ARM64)
    #define CURRENT_ARCH "ARM64"
#elif defined(__arm__) || defined(_M_ARM)
    #define CURRENT_ARCH "ARM32"
#elif defined(__mips__)
    #define CURRENT_ARCH "MIPS"
#else
    #error "Cannot detect processor's architecture"
#endif
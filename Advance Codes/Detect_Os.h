
#if defined(_WIN32)
    #define CURRENT_OS "Windows"
#elif defined(__linux)
    #define CURRENT_OS "Linux"
#elif defined(__APPLE__) || defined(TARGET_OS_MAC)
    #define CURRENT_OS "MacOS"
#else 
    #error "Cannot detect operating system"
#endif
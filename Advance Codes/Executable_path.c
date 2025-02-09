#include<stdio.h>

#define MAX_LEN_OF_PATH_TO_EXECUTABLE (unsigned long)255

inline static unsigned long getExecutablePath( char[MAX_LEN_OF_PATH_TO_EXECUTABLE] );

#if defined ( _WIN64 )
    
    #include <Windows.h>
    inline static unsigned long getExecutablePath( char __path[MAX_LEN_OF_PATH_TO_EXECUTABLE] )
    {
        return GetModuleFileName(NULL, __path , MAX_LEN_OF_PATH_TO_EXECUTABLE);
    }

#elif defined( __linux__ )

    #include<unistd.h>
    inline static unsigned long getExecutablePath( char __path[MAX_LEN_OF_PATH_TO_EXECUTABLE])
    {
        return readlink("/proc/self/exe", __path , MAX_LEN_OF_PATH_TO_EXECUTABLE - 1);
    }
#elif defined ( __APPLE__ )

    #include<mac-o/dyld.h>
    inline static unsigned long getExecutablePath( char __path[MAX_LEN_OF_PATH_TO_EXECUTABLE])
    {
        uint32_t size = sizeof( __path );
        _NSGetExecutablePath(path, &size);
        return size;
    }
#else
    #error "Cannot detect your Operating system. This code can work only with Windows, Linux and MacOS."
#endif


int main ( void )
{
    char exec_path[MAX_LEN_OF_PATH_TO_EXECUTABLE] = {0};
    
    unsigned long len = getExecutablePath(exec_path);

    printf("\n |> Exec's path : '%s' with len= %lu", exec_path, len);
}
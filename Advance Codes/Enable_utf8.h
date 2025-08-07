#ifndef UTF_SUPPORT_H
#define UTF_SUPPORT_H

#ifdef _WIN64
    #include <Windows.h>
    #include <io.h>
    #include <fcntl.h>
    #include <stdio.h>
#else
    #include <locale.h>
    #include <wchar.h>
    #include <stdio.h>
#endif

/// Don't forget to pass these flags to the compiler:
///          -fexec-charset=UTF-8 -finput-charset=UTF-8

inline static void enableUtfSupport() 
{
    #ifdef _WIN64 
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        
        _setmode(_fileno(stdout), _O_U16TEXT);
        _setmode(_fileno(stdin), _O_U16TEXT);

    #else
        setlocale(LC_ALL, "");
        // You should use wprintf and fgetwc for wide character output/input
    #endif
}

#endif
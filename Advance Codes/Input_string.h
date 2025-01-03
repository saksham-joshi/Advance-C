#include<stdio.h>
#include<stdlib.h>

inline static char* copyDataAndFree(char* __str, unsigned long __length)
{
    char* original = __str;
    char *copy = (char*) calloc(__length*2, sizeof(char));
    
    if(copy == NULL) return NULL;

    char* iterator = copy;

    while(*__str){
        *iterator = *__str;
        ++iterator;
        ++__str;
    }

    *iterator = '\0';

    free(original);

    return copy;
}

typedef struct {
    char* str;
    unsigned long len;
} SimpleStringStore;

inline static SimpleStringStore getDataFromConsole(unsigned long __buffer_size, const char __terminator)
{
    char *str = (char*) calloc(__buffer_size, sizeof(char));

    char* iterator = str;

    unsigned long index = 0;

    char ch = getchar();

    while(ch != __terminator)
    {
        if(index == __buffer_size)
        {
            str = copyDataAndFree(str, index);
            iterator = str + index;
            __buffer_size *= 2;
        }

        *iterator = ch;

        ++iterator;

        ++index;

        ch = getchar();
    }

    *iterator = '\0';

    SimpleStringStore obj;
    obj.str = str;
    obj.len = index;

    return obj;
}

inline static SimpleStringStore getLine(const char* __message)
{
    printf("%s",__message);
    return getDataFromConsole(8, '\n');
}

// ================== A Sample of how to get input ======================= //
// int main()
// {
//     SimpleStringStore obj = getLine("\n ==> Enter a number :- ");

//     printf("\n Output = '%s'\n =| Length = %lu", obj.str , obj.len);

//     free(obj.str);

//     return 0;
// }
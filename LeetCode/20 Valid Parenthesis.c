char GLOBAL_ARRAY__[10001];

inline static bool checkEquality(char __ch , char* __index)
{
    if(__index < GLOBAL_ARRAY__) return true;

    return __ch != *__index;
}

inline static bool isValid(const char* __str)
{
    char* index = GLOBAL_ARRAY__;

    while(*__str)
    {

        switch(*__str)
        {
            case '[' :

            case '(' :

            case '{' : *index++ = *__str;  break;

            case ']' : if (checkEquality('[' , --index)) { return false; } break;

            case '}' : if (checkEquality('{' , --index)) { return false; } break;

            case ')' : if (checkEquality('(' , --index)) { return false; } break;
        }

        ++__str;
    }

    return index == GLOBAL_ARRAY__;
}
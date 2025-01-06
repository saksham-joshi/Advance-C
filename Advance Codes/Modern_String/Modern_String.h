/******************************************************************************
 * Project Name: Modern String
 * File Name: Modern_String.h
 * Author: Saksham Joshi
 * Email: social.sakshamjoshi@gmail.com
 * Github: github.com/saksham-joshi
 * Linkedin: linkedin.com/in/sakshamjoshi27
 *
 * License:
 * This file is licensed under the GNU GENERAL PUBLIC LICENSE. You are free to use,
 * modify, and distribute this code for any purpose, with or without attribution.
 * 
 * DISCLAIMER: This code is provided "as is," without any warranty of any kind,
 * express or implied. The author is not responsible for any damages arising
 * from the use of this software.
 *
 * Copyright (c) [2025] Saksham Joshi. All rights reserved.
 *****************************************************************************/

#include "headers/Modern_String_functions.h"

/*==| Implementation of previously declared functions |==*/

/*
 @param __obj: pointer to instance of struct ModernString
 @param __str: a const char* which is added to the end of __obj._str

 This function adds up the content in __str to __obj._str.

*/
inline void appendString(MstrPtr __obj , const char* __str)
{
    while(*__str) pushBackString(__obj, *__str++);
}

/*
 @param __obj: pointer to instance of struct ModernString
 @param __index: index from where character is extracted
 
 If the value of __index is larger than or equal to __obj->_len,
 then it sets the error code MODERN_STRING_ERROR_INDEX_OUT_OF_BOUND
 and returns the MODERN_STRING_NULL_TERMINATOR
*/
inline char atString(MstrPtr __obj , ULongLong __index)
{
    if(__obj->_len > __index) return __obj->_str[__index];
    errno = MODERN_STRING_ERROR_INDEX_OUT_OF_BOUND;
    return MODERN_STRING_NULL_TERMINATOR;
}

/*
 @param __obj: pointer to instance of struct ModernString

 Converts the first letter to upper case and 
 rest of other characters to lower case
*/
inline void capitalizeString(MstrPtr __obj)
{
    if(__obj->_len > 0)
    {
        __obj->_str[0] = toupper(__obj->_str[0]);
        
        char* iterator = __obj->_str+1;

        while(*iterator)
        {
            *iterator = tolower(*iterator);
            ++iterator;
        }
    }
}

/*
 @param __obj: pointer to instance of struct ModernString

 Clears all the content in the string but do not deallocates
 underlying memory!
*/
inline void clearString(MstrPtr __obj) 
{
    __obj->_len = 0;
    __obj->_str[0] = MODERN_STRING_NULL_TERMINATOR;
}

/*
 @param __obj: pointer to instance of struct ModernString
 
 Creates a copy of all the characters but does not copies
 the max memory allocated.
*/
inline ModernString copyString(MstrPtr __obj)
{
    ModernString copy = {0};
    copy._len = __obj->_len;
    copy._allocated = __obj->_len + 1 ;

    copy._str = (char*) calloc(copy._allocated , sizeof(char));

    // if enough memory is not allocated ...
    if(!copy._str){
        errno = MODERN_STRING_ERROR_MEMORY_NOT_AVAILABLE;
        ModernString temp = {0};
        temp._len = temp._allocated = 0;
        temp._str = NULL;
        return temp;
    }

    char* iterator_at_copy = copy._str;
    const char* iterator_at_original = __obj->_str;

    while(*iterator_at_original)
    {
        *iterator_at_copy = *iterator_at_original;
        ++iterator_at_copy;
        ++iterator_at_original;
    }

    *iterator_at_copy = MODERN_STRING_NULL_TERMINATOR;

    return copy;
}

/*
 @param __obj: pointer to instance of struct ModernString
 @param __ch: character to count in __obj
 
 Counts the total no of occurences of a character
 in ModernString.
*/
inline ULongLong countString(MstrPtr __obj, char __ch)
{
    ULongLong count = 0;

    const char* iterator = __obj->_str;

    while(*iterator) if(*iterator++ == __ch) ++count;
    
    return count;
}

/*
 @param __obj: pointer to instance of struct ModernString
 @param __index: position of the character to delete.
 
 Removes the character at given position.
*/
inline void deleteCharString(MstrPtr __obj, const ULongLong __index)
{
    if(__index >= __obj->_len){
        errno = MODERN_STRING_ERROR_INDEX_OUT_OF_BOUND;
        return;
    }

    char* previous_iterator = __obj->_str + __index;
    const char* iterator = previous_iterator + 1;

    while(*iterator)
    {
        *previous_iterator = *iterator;
        ++previous_iterator;
        ++iterator;
    }

    *previous_iterator = MODERN_STRING_NULL_TERMINATOR;

    --__obj->_len;
}

/*
 @param __obj: pointer to instance of struct ModernString
 @param __from: position from where deletion which starts 
 @param __to : position to which deletion will end.
 
 Removes the character at the given range.
*/
inline void deletePartString(MstrPtr __obj, const ULongLong __from, const ULongLong __to)
{
    if(__from >= __obj->_len || __to > __obj->_len)
    {
        errno = MODERN_STRING_NULL_TERMINATOR; 
        return;
    }
    else if(__obj->_len == 0 || __from >= __to) return;

    char* writing_iterator = __obj->_str + __from;
    const char* reader_iterator = __obj->_str + __to;

    __obj->_len -= (__to - __from);

    while(*reader_iterator)
    {
        *writing_iterator = *reader_iterator;
        ++writing_iterator;
        ++reader_iterator;
    }

    *writing_iterator = MODERN_STRING_NULL_TERMINATOR;
}


/* Frees up the __obj._str and turns it to NULL. Sets len as 0*/
inline void destroyString(MstrPtr __obj)
{
    free(__obj->_str);
    __obj->_allocated = __obj->_len = 0;
    __obj->_str = NULL;
}

inline const char* getConstCharString(MstrPtr __obj)
{
    return __obj->_str;
}

/* 
  Returns the first occurrence of the given string. 
   
  If not found, returns MODERN_STRING_MAX_STRING_LEN
*/
inline ULongLong indexString(MstrPtr __obj , char __ch)
{
    const char* iterator = __obj->_str;

    while(*iterator && *iterator != __ch) ++iterator;

    return (*iterator) ? (iterator - __obj->_str) : MODERN_STRING_MAX_STRING_LEN;
}

/* Checks whether the given string contains only alphabetical characters or not*/
inline ModernStringBool isAlphabetString(MstrPtr __obj)
{
    const char* iterator = __obj->_str;

    while(*iterator) if(!isalpha(*iterator++)) return MODERN_STRING_FALSE;

    return MODERN_STRING_TRUE;
}

/* Checks whether the given string contains only alphabetical and numeric characters or not*/
inline ModernStringBool isAlphaNumericString(MstrPtr __obj)
{
    const char* iterator = __obj->_str;

    while(*iterator) if (!isalnum(*iterator++)) return MODERN_STRING_FALSE;

    return MODERN_STRING_TRUE;
}

/* Checks whether the given string contains only numeric characters or not*/
inline ModernStringBool isNumericString(MstrPtr __obj)
{
    const char* iterator = __obj->_str;

    while(*iterator) if (!isdigit(*iterator++) ) return MODERN_STRING_FALSE;

    return MODERN_STRING_TRUE;
}

/* Checks whether the given string is empty or not */
inline ModernStringBool isEmptyString(MstrPtr __obj)
{
    return (__obj->_len == 0) ? MODERN_STRING_TRUE : MODERN_STRING_FALSE;
}

/* Checks if the given string is equal or not*/
inline ModernStringBool isEqualString(MstrPtr __obj1 , MstrPtr __obj2)
{
    if(__obj1->_len != __obj2->_len) return MODERN_STRING_FALSE;
    
    const char* iter1 = __obj1->_str;
    const char* iter2 = __obj2->_str;

    while(*iter1)
    {
        if(*iter1 != *iter2) return MODERN_STRING_FALSE;
        ++iter1;
        ++iter2;
    }

    return MODERN_STRING_TRUE;

}

/* Checks whether the given string is in lower case or not. */
inline ModernStringBool isLowerCaseString(MstrPtr __obj)
{
    const char* iterator = __obj->_str;

    while(*iterator){ 
        if(*iterator != tolower(*iterator)) return MODERN_STRING_FALSE;
        ++iterator;
    }

    return MODERN_STRING_TRUE;
}

/* Checks whether the given string is in upper case or not. */
inline ModernStringBool isUpperCaseString(MstrPtr __obj)
{
    const char* iterator = __obj->_str;

    while(*iterator){ 
        if(*iterator != toupper(*iterator)) return MODERN_STRING_FALSE;
        ++iterator;
    }
    return MODERN_STRING_TRUE;
}

/*
 Returns the length of the string
*/
inline ULongLong lenString(MstrPtr __obj)
{
    return __obj->_len;
}

/*
 Creates the instance of ModernString and copies the content in __str.
*/
inline ModernString makeString(const char* __str)
{
    ModernString output = {0};

    output._allocated = 8;
    output._str = (char*) calloc(output._allocated, sizeof(char));
    output._len = 0;

    while(*__str) pushBackString(&output, *__str++);

    return output;
}

/*
 Creates the instance of ModernString which contains an empty string of length 0.
*/
inline ModernString makeEmptyString(void)
{
    ModernString obj = {0};

    obj._str = (char*) calloc(1 , sizeof(char));
    obj._allocated = 1;
    obj._len = 0;
    return obj;
}

/*
   Reserves a memory in advance while creating the Instance.
*/
inline ModernString makeReservedString(unsigned long __allocation)
{
    // 0 bytes of memory cannot be allocated
    __allocation += (__allocation == 0) ? 1 : 0;

    ModernString obj = {0};

    obj._str = (char*) calloc(__allocation , sizeof(char));

    if(!obj._str)
    {
        errno = MODERN_STRING_ERROR_MEMORY_NOT_AVAILABLE;
        return obj;
    }

    *obj._str = MODERN_STRING_NULL_TERMINATOR;
    obj._len = 0;
    obj._allocated = __allocation;
    return obj;

}

/*
 Extracts the last character from the string, deletes it and returns it.

 If the string is empty, returns '\0' null terminator
*/
inline char popBackString(MstrPtr __obj)
{
    if(__obj->_len != 0)
    {
        char temp = __obj->_str[__obj->_len-1];
        __obj->_str[--__obj->_len] = MODERN_STRING_NULL_TERMINATOR;
        return temp;
    }
    errno = MODERN_STRING_ERROR_INDEX_OUT_OF_BOUND;
    return MODERN_STRING_NULL_TERMINATOR;
}

/*
 Extracts the front character from the string, deletes it and returns it.

 If string is empty, return '\0' null terminator.
*/
inline char popFrontString(MstrPtr __obj)
{
    if(__obj->_len == 0) return MODERN_STRING_NULL_TERMINATOR;

    char output = __obj->_str[0];

    const char* iterator = __obj->_str+1;
    char *previous_iterator = __obj->_str;

    while(*iterator)
    {
        *previous_iterator = *iterator;
        ++previous_iterator;
        ++iterator;
    }

    *previous_iterator = MODERN_STRING_NULL_TERMINATOR;

    --__obj->_len;

    return output;
}

inline void printString(MstrPtr __obj)
{
    if(__obj) printf("%s", __obj->_str);
}

inline void printlnString(MstrPtr __obj)
{
    if(__obj) puts(__obj->_str);
}

/*
 Inserts the new character at the end of the string.

 If the character cannot fit into the string, then it
 reallocates the double memory, copy the content and then 
 inserts the character.
*/
inline void pushBackString(MstrPtr __obj , char __ch)
{
    if(__obj->_len == __obj->_allocated-1)
    {
        char *new_ptr = (char*) calloc(__obj->_allocated*2, sizeof(char));
        
        // now we will copy the content to new_ptr
        const char* iterator_at_old_string = __obj->_str;
        char* iterator_at_new_string = new_ptr;

        while(*iterator_at_old_string)
        {
            *iterator_at_new_string = *iterator_at_old_string;
            ++iterator_at_new_string;
            ++iterator_at_old_string;
        }

        *iterator_at_new_string = '\0';

        free(__obj->_str);
        __obj->_str = new_ptr;
        __obj->_allocated *= 2;
    }
    __obj->_str[__obj->_len] = __ch;
    ++__obj->_len;
    __obj->_str[__obj->_len] = MODERN_STRING_NULL_TERMINATOR;

}

/*
 Replaces the __replacer in __obj with __replacement

 Example- "H E L L O"
           replaceCharString(..., ' ' , '_')
           Output- "H_E_L_L_O"
*/
inline void replaceCharString(MstrPtr __obj, char __replacer , char __replacement)
{
    char* iterator = __obj->_str;

    while(*iterator)
    {
        if(*iterator == __replacer) *iterator = __replacement;
        ++iterator;
    }
}

/*
 Reverses the given string
*/

inline void reverseString(MstrPtr __obj)
{
    if(__obj->_len == 0) return;

    char* iterator_start = __obj->_str;
    char* iterator_end = __obj->_str + __obj->_len - 1;

    while(iterator_start < iterator_end)
    {
        char temp = *iterator_start;
        *iterator_start = *iterator_end;
        *iterator_end = temp;

        ++iterator_start;
        --iterator_end;
    }
}

/*
 Returns the first occurrence index of the given character if it is searched from last.
 
 If not found, returns MODERN_STRING_MAX_STRING_LEN
*/
inline ULongLong rindexString(MstrPtr __obj  , char __ch)
{
    const char* reverse_iterator = __obj->_str + __obj->_len - 1;

    while(reverse_iterator >= __obj->_str && *reverse_iterator != __ch) -- reverse_iterator;

    return (reverse_iterator >= __obj->_str) ? reverse_iterator - __obj->_str : MODERN_STRING_MAX_STRING_LEN;
}

// sorts the given string in ascending order
inline void sortString(MstrPtr __obj)
{

}

/*
 This function iterates through the whole string and returns ModernStringStats instance.
 It calculates:
     1. No. of vowel in capital and in small letter
     2. No. of consonant in capital and small letter
     3. No. of digits
     4. No. of spaces
     5. No. of newlines
     6. No. of opening and closing curly brackets.
     7. No. of opening and closing round brackets.
     8. No. of opening and closing square brackets.
*/
inline ModernStringStats statsString(MstrPtr __obj)
{
    const char* iterator = __obj->_str;

    ModernStringStats stat_object = {0};

    while(*iterator)
    {
        if(*iterator >= '0' && *iterator <= '9') ++stat_object._digits;

        else if(*iterator == ' ') ++stat_object._spaces;

        else if(*iterator == '\n') ++stat_object._newlines;

        else if(*iterator == '[') ++stat_object._brackets._square._open;
        else if(*iterator == ']') ++stat_object._brackets._square._close;

        else if(*iterator == '(') ++stat_object._brackets._round._open;
        else if(*iterator == ')') ++stat_object._brackets._round._close;

        else if(*iterator == '{') ++stat_object._brackets._curly._open;
        else if(*iterator == '}') ++stat_object._brackets._curly._close;

        else if(*iterator == 'A' || *iterator == 'E' || *iterator == 'I' || *iterator == 'O' || *iterator == 'U') ++stat_object._alphabets._vowels._capital;
        else if(*iterator == 'a' || *iterator == 'e' || *iterator == 'i' || *iterator == 'o' || *iterator == 'u') ++stat_object._alphabets._vowels._small;

        else if(*iterator >= 'a' && *iterator <= 'z') ++stat_object._alphabets._consonants._small;

        else if(*iterator >= 'A' && *iterator <= 'Z') ++stat_object._alphabets._consonants._capital;
        
        else ++stat_object._misc;

        ++iterator;
    }

    return stat_object;
}

/*
 Returns a sub part of the given string.
 Example- "0123456789"
          subString(..., 3, 7)
          Output- "3456"
*/
inline ModernString subString(MstrPtr __obj , ULongLong __start , ULongLong __end)
{
    if(__start < __obj->_len && __end <= __obj->_len && __start < __end)
    {
        ModernString output = {0};

        output._len = __end - __start;
        output._allocated = output._len + 1;

        output._str = (char*) calloc(output._allocated , sizeof(char));

        const char* iterator_at_start = __obj->_str + __start;
        const char* iterator_at_end = __obj->_str + __end;
        
        char* iterator_at_output = output._str;

        while(iterator_at_start < iterator_at_end)
        {
            *iterator_at_output = *iterator_at_start;
            ++iterator_at_start;
            ++iterator_at_output;
        }
        *iterator_at_output = MODERN_STRING_NULL_TERMINATOR;

        return output;

    }

    return makeEmptyString();
}

/*
 Converts the given string to lower case
*/
inline void toLowerCaseString(MstrPtr __obj)
{
    char* iterator = __obj->_str;
    while(*iterator)
    {
        *iterator = tolower(*iterator);
        ++iterator;
    }
}

/*
 Converts the given stirng to upper case
*/
inline void toUpperCaseString(MstrPtr __obj)
{
    char* iterator = __obj->_str;
    while(*iterator)
    {
        *iterator = toupper(*iterator);
        ++iterator;
    }
}

/*
 Takes user input from terminal/console/Cmd and returns the ModernString
*/
inline ModernString takeInputString(const char* __message)
{
    printf("%s", __message);
    SimpleStringStore obj = getDataFromConsole(16, '\n');

    ModernString output = {0};
    output._allocated = obj.allocated_buffer_size;
    output._len = obj.len;
    output._str = obj.str;

    return output;
}

/*
 Removes the leading and trailing whitespaces, tabs and newlines.
*/
inline void trimString(MstrPtr __obj)
{
    if(__obj->_len == 0) return;

    const char* start_iterator = __obj->_str;
    const char* end_iterator = __obj->_str + __obj->_len - 1;

    while(*start_iterator && (*start_iterator == ' ' || *start_iterator == '\n' || *start_iterator == '\t')) ++start_iterator;

    if(start_iterator < end_iterator) while(end_iterator > start_iterator && (*end_iterator == ' ' || *end_iterator == '\n' || *end_iterator == '\t')) --end_iterator;

    __obj->_len = end_iterator - start_iterator + 1;

    char* writing_iterator = __obj->_str;

    for(ULongLong i = 0 ; i < __obj->_len ; ++i){
        *writing_iterator = *start_iterator;
        ++writing_iterator;
        ++start_iterator;
    }
    *writing_iterator = MODERN_STRING_NULL_TERMINATOR;
}


//#pragma clang diagnostic pop
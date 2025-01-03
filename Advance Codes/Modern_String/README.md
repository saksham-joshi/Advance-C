# Modern String in C
- This is a package which contains implementation of modern String in C language. 
- It provides several optimized functions written in C.

## How to use it?
- **Step 1**: Copy this whole folder to your project's directory.
- **Step 2**: Include 'String.h' file in your code like this:
```c
#include "String_imp/String.h"
```
- **Step 3**: To create a String, below is an example:
```c
#include "String_imp/String.h"

int main(void)
{
    ModernString str = makeString("Hello, World");
    printString(&str);
}
```
#### **NOTE**: Don't create instance of '**struct String**' directly. Instead, call '**makeString()**' functions which is as fast as creating an instance directly and it performs additional settings to make your string work stable.

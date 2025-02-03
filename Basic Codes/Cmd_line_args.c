/*
   Command line arguments are the values which we provide to the executable as some data!
*/

#include<stdio.h>

int main( int argc , char** argv )
{
    printf("\n | Passed arguments are: [ ");

    for(int i = 0 ; i < argc ; ++i)  printf(" '%s' ", argv[i]);
    
    printf(" ]");
}

/*
   Compile the code with the below given command
   
        > clang cmd_line_args.c -o output.exe
*/

/*
   Run the executuable with this command

        > .\output 1 2 3 4 5
             or
        > .\output 1,2,3,4,5
*/  
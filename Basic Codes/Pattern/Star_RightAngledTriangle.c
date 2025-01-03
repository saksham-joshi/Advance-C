#include<stdio.h>

int main(void)
{
    unsigned short int no_of_lines = 0;

    printf("\n ==> Enter the no of lines :- ");
    scanf_s("%hu", &no_of_lines);

    for(unsigned short int i = 1 ; i <= no_of_lines ; ++i){
        for(unsigned short int j = 0 ; j < i ; ++j){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

#include<stdio.h>

int main(void)
{
    const int row = 5, col = 5;

    int graph[row][col] = {
        {0,1,0,0,0},
        {0,0,0,0,1},
        {0,1,1,0,0},
        {0,0,0,1,0},
        {0,1,0,0,0}
    };

    printf("\n |=| Adjacent vertices are : [  ");
    for(int i = 0 ; i < 5 ; ++i)
    {
        for(int j = 0 ; j < 5 ; ++j)
        {
            if(graph[i][j])
            {
                printf("%c%c  ",65+i, 65+j);
            }
        }
    }
    printf("]");

    return 0;
}
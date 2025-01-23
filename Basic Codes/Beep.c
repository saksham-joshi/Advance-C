#include<windows.h>
int main(void)
{
    for(int i = 100 ; i <= 1000 ; i+=100)
    {
        Beep(700, i);
    }
    return 0;
}
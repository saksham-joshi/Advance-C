#include <stdio.h>
#include<conio.h>
#include<math.h>

inline float takeFloatInput(const char* __message)
{
    float value;

    printf("%s", __message);

    scanf_s("%f", &value);

    return value;
    
}

#define NUMBER_INPUT_MESSAGE "> Number:_"
#define OPERATOR_INPUT_MESSAGE "> Operator:_"

inline void calculator()
{
    float num = takeFloatInput(NUMBER_INPUT_MESSAGE);
    char operator;
    
    while(1)
    {
        printf("%s", OPERATOR_INPUT_MESSAGE);
        scanf_s(" %c", &operator);

        switch(operator)
        {
            case '+' : num = num + takeFloatInput(NUMBER_INPUT_MESSAGE); break;

            case '-' : num = num - takeFloatInput(NUMBER_INPUT_MESSAGE); break;

            case '*' : num = num * takeFloatInput(NUMBER_INPUT_MESSAGE); break;

            case 'x' : num = num * takeFloatInput(NUMBER_INPUT_MESSAGE); break;

            case 'X' : num = num * takeFloatInput(NUMBER_INPUT_MESSAGE); break;

            case '/' : num = num / takeFloatInput(NUMBER_INPUT_MESSAGE); break;

            case '%' : num = fmod(num , takeFloatInput(NUMBER_INPUT_MESSAGE)); break;

            default : printf("\n Invalid operator '%c' found!", operator); return;

        }

        printf(">> Output:_%f\n",num);
        
    }
}

int main(void)
{
    calculator();

    return 0;
}
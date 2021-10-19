#include <stdio.h>

/*текстовый калькулятор.
Пользователь вводит строку вида 12345+5678-1235/2567*12356

Программа должна выполнить все операции по порядку. То есть сначала 12345+5678
Потом -1235
потом /2567
и так далее.

Примерный алгоритм:
1. Ввод строки через getchar() в массив символов
2. В цикле идет анализ строки. Заводим временную переменную для хранения результата и еще одну переменную для следующего операнда
3. Когда доходим до символа с обозначением операции - запоминаем ее(можно завести переменную). Когда доходим до следующей операции - выполняем предыдущую операцию
и запоминаем промежуточный результат. И так до последнего символа(код \0)

Написать простой Makefile
*/

void make_operand(float *res, int tmp, char ch);

int main(void)
{
    float result = 0.f;

    printf("Enter the string to calculate:\n");

    int temp_val = 0;
    char next_operand;
    char ch;

    while ( (ch = getchar()) != '\n')
    {
         if (ch >= '0' && ch <= '9')
        {
            temp_val *= 10;
            temp_val += ch - '0';
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (next_operand)
            {
                make_operand(&result, temp_val, next_operand);
            }
            else
            {
                result = temp_val;
            }
            next_operand = ch;
            temp_val = 0;
        }
    }
    make_operand(&result, temp_val, next_operand);

    printf("Result: %.3f\n", result);
    return 0;
}

void make_operand(float *result, int tmp, char ch)
{
    if (ch == '+') *result += tmp;
    else if (ch == '-') *result -= tmp;
    else if (ch == '*') *result *= tmp;
    else if (ch == '/') *result /= tmp;
}


#include <stdio.h>
#include <stdbool.h>

/*
Реализовать через getchar() функционал для считывания строки в переменную типа float или double. И продемонстрировать работу алгоритма(функции)

например
float get_float(void)
{
float result;
// магия с getchar() и result
return result;
}
*/

// получить со стандартного потока ввода через getchar float
float get_float(void);

// возведение в степень десятки (10^n)
unsigned int my_pow(unsigned int);

int main(void)
{
    float number = get_float();
    if (number != 0)
    {
        printf("Float number is %.2f\n", number);
    }
    else printf("Float number is not found!\n");

    return 0;
}

float get_float()
{
    char c;
    float result = 0;
    int digit_counter = 0;
    unsigned int decimal_place = 0;
    bool isValuePositive = true;

    while((c = getchar()) != '\n') {
        if (c == '-') isValuePositive = false;
        if (c >= '0' && c <= '9') {
            digit_counter += 1;
            result *= 10;
            result += c - '0';
        }
        if (c == '.' || c == ',')
        {
            decimal_place = digit_counter;
            // result += c - '.';
        }
    }

    if (decimal_place > 0 && digit_counter > 0)
    {
        result /= my_pow(digit_counter - decimal_place);
    }
    else return 0;    
    return isValuePositive ? result : -result;
}

unsigned int my_pow(unsigned int p)
{
    unsigned int result = 1;
    for (int i = p; i > 0; i--)
    {
        result *= 10;
    }
    return result;
}


#include <stdio.h>

/*
Программа - имитатор датчика температуры.

Генерирует файл с измерениями вида day;month;year;temperature
Например:
1;1;2000;-10
1;5;2001;20
2;5;2001;25
19;10;2021;5
20;10;2021;10
21;11;2020;-500

Исходные данные заполняются либо случайным образом, либо в цикле(по вашему усмотрению).
Количество измерений - любое.
Пример программы для считывания на guthub/lesson10/structs/read_measurements_from_file
Подсказка: для записи в файл можно использовать fprintf
Программа должна быть модульной. Составить Makefile
*/

#include "utils.h"

int main(void)
{
    int N;
    char c;
    measure_t array[N];
    char answer[4];
    int retcode;
    int temp_val = 0;

    printf("Please enter number of generated data: ");
    // scanf("%d", &N);

    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            temp_val *= 10;
            temp_val += c - '0';
        }
    }
    N = temp_val;
    if (N > 0)
    {
        generate_data_array(array, N);
        print_measurements(array, N);
        if (interactive_user() == 1)
        {
            write_to_file(array, N, "output.txt");
            printf("Done.\n");
        }
        else return 0;
    }
    else 
    {
        printf("Error!");
        return -1;
    }
    return 0;
}

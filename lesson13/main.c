#include <stdio.h>
#include <unistd.h> //getopt
#include <string.h> //strcpy
#include <stdbool.h> //bool
#include "temp_functions.h"


#ifdef DEBUG
    #define DBG_d(msg, d) if (verbose_flag) printf("debug: %s%d\n", msg, d)
    #define DEBUG_MESSAGE(msg) if (verbose_flag) printf("debug: %s\n", msg) 
#else
    #define DEBUG_MESSAGE(x)
    #define DBG_d(x,y)
#endif

#define OPT_LIST "vf:m:h"

/*
Создание консольного приложения - Статистика температуры.
Необходимо реализовать консольное приложение, которое
осуществляет считывание текстового файла csv, состоящего из
строк следующего формата:
YEAR;MONTH;DAY;HOUR;MINUTE;TEMPERATURE
dddd;mm;dd;hh;mm;temperature
temperature - целое число от -99 до 99

Необходимо вывести статистику по каждому месяцу, с учетом
исходных данных:
• среднемесячная температура
• минимальная температура в текущем месяце
• максимальная температура в текущем месяце
Также необходимо вывести статистику за год:
• среднегодовая температура
• минимальная температура
• максимальная температура

Приложение должно корректно работать на любых входных
данных, если формат csv файла не соответствует заданному, то
необходимо указать номер строки файла csv, в которой
обнаружена ошибка и не учитывать данную строку.
*/


int count_lines(const char *file);

int main(int argc, char **argv)
{
    int get_month[12]; /* для хранения заданных месяцев через аргумент -m*/
    int get_count_of_month = 0; /* для хранения кол-ва через -m */
    int temp_val = 0;
    int ret;
    bool verbose_flag = false;
    char input_textfile[50];
    opterr = 0;
    while((ret = getopt(argc, argv, OPT_LIST)) != -1)
    {
        switch(ret)
        {
            // f - filename to generate
            case 'f': {
                #ifdef DEBUG
                printf("option -%c with argument '%s'.\n", ret, optarg);                
                #endif
                strcpy(input_textfile, optarg);
                break;
            }
            // verbose, debug
            case 'v': {
                verbose_flag = true;
                printf("option -c: verbose %d\n", verbose_flag);
                #ifndef DEBUG
                    printf("No verbose. File maked without -DDEBUG flag\n");
                #endif
                break;
            }
            /* m - номер месяца. Если задан данный ключ, то выводится только
            статистика за указанный месяц*/
            case 'm': {
                #ifdef DEBUG
                    printf("option -%c with argument '%s'.\n", ret, optarg);
                #endif
                if (atoi(optarg) > 0 && atoi(optarg) <= 12)
                {
                    get_month[get_count_of_month] = atoi(optarg);
                    get_count_of_month++;
                }
                else
                printf("option -%c should be with argument 0..12\n", ret);
                break;
            }
            /* Описание функционала приложения. Список ключей, которые обрабатывает данное приложение*/
            case 'h': {
                printf("Usage: %s [OPTION]\n", argv[0]);
                printf("\t-f\t Source filename\n");
                printf("\t-m\t Select the month or few months to display the statictics (1-12)\n\t  \tEx. -m 3 -m 5");
                printf("\t-h\t Display current info\n");
                printf("\t-v\t Verbose for debugging. Should make with -DDEBUG flag\n");
                printf("Display statistics for each month, from input data, aswell statistics for the year\n");
                return 0;
            }
            case '?': {
                if (optopt == 'f')
                    fprintf(stderr, "Error. Option -%c requires an argument/\n", optopt);
                else
                    fprintf(stderr, "Error. Unknown option character '\\x%x'.\n", optopt);                
                return -1;
            }
        }
    }
    int array_size = count_lines(input_textfile);
    DBG_d("Count lines of input data: ", array_size);
    // measure_t *array = malloc(sizeof(measure_t) * array_size);

    if (array_size > 0)
    {
        DEBUG_MESSAGE("Initialization..");
        measure_t *arr = (measure_t *)malloc(sizeof(measure_t) * array_size);
        /* Читаем файл и записываем в массив структур */
        arr = read_measurements_f_file(input_textfile, &array_size);
        if (verbose_flag) print_measurements(arr, array_size); 
        printf("Analyzed %d lines of input data. Results are: \n", array_size);

        /* Создаем массивы для помесячных значений */
        int month_temp_max[12];
        int month_temp_min[12];
        float month_temp_avg[12];
        /* Заполняем массивы помесячно исходя из полученных данных */
        max_temp_month_by_month(arr, array_size, month_temp_max);
        min_temp_month_by_month(arr, array_size, month_temp_min);
        avg_temp_month_by_month(arr, array_size, month_temp_avg);

        /* Если задан конкретный месяц */
        if (get_count_of_month > 0)
        {
            print_data(month_temp_max, month_temp_min, month_temp_avg, get_count_of_month, get_month);
        }
        else
        {
            /* Выводим информацию помесячно */
            print_data(month_temp_max, month_temp_min, month_temp_avg, 12, NULL);

            printf("YEAR STATISTICS:\n");
            printf("==============\n");
            printf("min temp: %d\n", min_temp(arr, array_size));
            printf("max temp: %d\n", max_temp(arr, array_size));
            printf("avg temp: %.1f\n", avg_temp(arr, array_size));
        }
        /* Освобождаем память */
        free(arr);
        return 0;
    }
    printf("Error in input data. Help information -h flag\n");
    return -1;
}

int count_lines(const char *file)
{
    FILE *f = fopen(file, "r");
    if(!f) return -1;
    char ch;
    int lines = 0;
    while(!feof(f))
    {
        ch = fgetc(f);
        if (ch == '\n')
        {
            lines++;
        }
    }
    return lines;
}

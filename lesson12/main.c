#include <stdio.h>
#include <unistd.h> //getopt
#include <string.h> //strcpy
#include <stdbool.h> //bool
#include "utils.h"

bool verbose_flag = false;

#ifdef DEBUG
    #define DBG(msg, m) if (verbose_flag) printf("debug: %s%s\n", msg, m) 
    #define DEBUG_MESSAGE(msg) if (verbose_flag) printf("debug: %s\n", msg) 
#else
    #define DBG(x,y) 
    #define DEBUG_MESSAGE(x)
#endif

/*
Опции командной строки теперь необходимо обрабатывать через getopt()
По возможности использовать динамическую аллокацию памяти для массивов вместо статической(malloc/free)

Для примера 10 ДЗ.

Опция -f <filename> - имя файла для генерации
Опция -n <count> - количество значений для генерации
Опция -v - подробный вывод. Если эта опция присутствует, программа должна генерировать отладочные сообщения, если программа собрана с -DDEBUG

Пример макроса(Можете определить свой с максимально удобным для вас видом) для вывода отладочных сообщений(Макрос должен быть объявлен после объявления структуры):

define DBG(msg, m) printf("message %s: day %d month %d year %d temp %d\n, msg, m.day, m.month, m.year, m.temp)
кусок примера из l10-hometask
struct measurement meas[31];//0-30

for (int i = 0; i < 31; i++) {
    fprintf(f, "%d;%d;%d;%d\n", 
       meas[i].day,
       meas[i].month,
       meas[i].year,
       meas[i].temp );
    DBG("write into file", meas[i]);
}
*/


int main(int argc, char **argv)
{
    int N;
    char c;
    char answer[4];
    int retcode;
    int temp_val = 0;
    int ret;
    bool is_output_file_defined = false;
    char output_textfile[50] = "output.txt";
    while((ret = getopt(argc, argv, "fnv")) != -1)
    {
        switch(ret)
        {
            // f - filename to generate
            case 'f': {
                DBG("output filename: ", argv[optind]);
                strcpy(output_textfile, argv[optind]);
                is_output_file_defined = true;
                break;
            }
            // n - количество значений
            case 'n': {
                DBG("number of values to generate: ", argv[optind]);
                N = atoi(argv[optind]);
                break;
            }
            // verbose, debug
            case 'v': {
                DEBUG_MESSAGE("getopt verbose");
                verbose_flag = true;
                #ifndef DEBUG
                    printf("No verbose. File maked without -DDEBUG flag\n");
                #endif
                break;
            }
            case '?': {
                DEBUG_MESSAGE("Unknown operation");
                break;
            }
        }
    }
    measure_t *array = malloc(sizeof(measure_t) * N);
    // printf("Please enter number of generated data: ");

    // while ((c = getchar()) != '\n')
    // {
    //     if (c >= '0' && c <= '9')
    //     {
    //         temp_val *= 10;
    //         temp_val += c - '0';
    //     }
    // }
    // N = temp_val;
    if (N > 0)
    {
        DEBUG_MESSAGE("Initialization..");
        generate_data_array(array, N, verbose_flag);
        DEBUG_MESSAGE("Data generated.\n");
        // print_measurements(array, N);
        if (interactive_user(is_output_file_defined) == 1)
        {
            write_to_file(array, N, output_textfile);         
            DEBUG_MESSAGE("File created. Check it out!\n");
        }
        else {
            write_to_file(array, N, output_textfile);
            DEBUG_MESSAGE("File created. Check it out!\n");
        }
        free(array);
        return 0;
    }
    else 
    {
        printf("Error! Please enter number of values\n");
        return -1;
    }
}

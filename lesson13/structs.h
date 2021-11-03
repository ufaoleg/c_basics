#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* allocation */

#define MAX_LEN 128
#define MAX_ARRSIZE 128

/*  Структурный тип для представления сбора информации
    с датчика температуры, необходимые поля:
    дата (день, месяц, год), время (час, минута) и температура от -99 до 99.
*/ 
typedef struct measurements {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int temp;
} measure_t;

typedef struct temp_report {
    int temp;
    char date[30];
} temp_report_t;

char *parse_month(int month);

measure_t *read_measurements_f_file(const char *file,int *array_size);
void print_measurements(measure_t *measure, int measure_size);

#endif
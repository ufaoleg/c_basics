#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdio.h>

/*  Структурный тип для представления сбора информации
    с датчика температуры, необходимые поля:
    дата (день, месяц, год) и температура.
*/ 
typedef struct measurements {
    int day;
    int month;
    int year;
    float temp;
} measure_t;

int read_measurements_f_file(measure_t *measure, const char *file);
void print_measurements(measure_t *measure, int measure_size);

#endif
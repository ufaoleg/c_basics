#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"
//#include <str

// day;month;year;temperature
int generate_day_i(int seed);
int generate_month_i(int seed);
int generate_year_i(int seed);
float generate_temp_f(int seed);

void generate_data_array(measure_t *arr_measures, int arr_size);
void write_to_file(measure_t *arr_measures, int arr_size, const char *file);

// пользовательская функция сравнения строк
int str_compare(const char *s1, const char *s2);

int interactive_user(void);

#endif
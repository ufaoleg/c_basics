#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"
#include <stdbool.h>

/* Значение для проверки, содержатся ли какие-то данные */
#define EMPTY_VALUE 999

/* Функции для подсчёта целого массива */
float avg_temp(measure_t *array, int arr_size);
int max_temp(measure_t *array, int arr_size);
int min_temp(measure_t *array, int arr_size);

/* Подфункции для подсчёта помесячно*/
int max_temp_in_month(measure_t *array, int month, int arr_size);
int min_temp_in_month(measure_t *array, int month, int arr_size);
float avg_temp_in_month(measure_t *array, int month, int arr_size);

/* функция для подсчёта помесячно*/
int *max_temp_month_by_month(
    measure_t *array, int arr_size, int *max_temp_month);
int *min_temp_month_by_month(
    measure_t *array, int arr_size, int *min_temp_month);
float *avg_temp_month_by_month(
    measure_t *array, int arr_size, float *avg_temp_month);

bool check_data_w_msg(int value, bool *is_exists, const char *msg);
void print_data(int *month_temp_max, int *month_temp_min, float *month_temp_avg, int arr_size, int *months);

#endif
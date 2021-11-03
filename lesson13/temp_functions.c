#include "temp_functions.h"

float avg_temp(measure_t *array, int arr_size)
{
    int sum = 0;
    
    for (int i = 0; i< arr_size; i++)
    {
        sum += array[i].temp;
    }
    return (float) sum / arr_size;
}

int max_temp(measure_t *array, int arr_size)
{
    int max = array[0].temp;
    for (int i = 1; i < arr_size;i++)
    {
        if (array[i].temp > max) max = array[i].temp;
    }
    return max;
}

int min_temp(measure_t *array, int arr_size)
{
    int min = array[0].temp;
    for (int i = 1; i < arr_size; i++)    
    {
        if (array[i].temp < min) min = array[i].temp;
    }
    return min;
}

int max_temp_in_month(measure_t *array, int month, int arr_size)
{
    int max = array[0].temp;
    int counter = 0;
    for (int j = 1; j < arr_size; j++)
    {
        if (array[j].month == month)
        {
            if (array[j].temp > max) max = array[j].temp;
            counter++;
        }
    }
    if (counter == 0) return EMPTY_VALUE;
    return max;
}

int min_temp_in_month(measure_t *array, int month, int arr_size)
{
    int min = array[0].temp;
    int counter = 0;
    for (int j = 1; j < arr_size; j++)
    {
        if (array[j].month == month)
        {
            if (array[j].temp < min) min = array[j].temp;
            counter++;
        }
    }
    if (counter == 0) return EMPTY_VALUE;
    return min;
}

float avg_temp_in_month(measure_t *array, int month, int arr_size)
{    
    int sum = 0; 
    int count = 0;
    for (int j = 1; j < arr_size; j++)
    {
        if (array[j].month == month)
        {
            sum += array[j].temp;
            count++;
        }
    }
    if (count == 0 || sum == 0) return EMPTY_VALUE;
    return (float) sum / count;
}

int *max_temp_month_by_month(measure_t *array, int arr_size, int *max_temp_month)
{
    for (int i = 1; i <=12 ; i++)
    {
        max_temp_month[i] = max_temp_in_month(array, i, arr_size);
   }
   return max_temp_month;
}

int *min_temp_month_by_month(measure_t *array, int arr_size, int *min_temp_month)
{
    for (int i = 1; i <=12 ; i++)
    {
        min_temp_month[i] = min_temp_in_month(array, i, arr_size);
   }
   return min_temp_month;
}

float *avg_temp_month_by_month(measure_t *array, int arr_size, float *avg_temp_month)
{
    for (int i = 1; i <=12 ; i++)
    {
        avg_temp_month[i] = avg_temp_in_month(array, i, arr_size);
   }
   return avg_temp_month;
}

bool check_data_w_msg(int value, bool *is_exists, const char *msg)
{
    if (value != 999) {
        *is_exists = true;
        printf("%s: %d\n", msg, value);
        return true;
    }
    *is_exists = false;    
    return false;
}

void print_data(int *month_temp_max, int *month_temp_min, float *month_temp_avg, int arr_size, int *months)
{
    int sz = months ? arr_size -1 : arr_size;
    for (int i= months ? 0 : 1; i <= sz; i++)
    {
        bool max_exists = false;
        bool min_exists = false;
        bool avg_exists = false;
        
        printf("%s\n", parse_month(months ? months[i] : i));
        printf("============\n");
                    
        check_data_w_msg(month_temp_max[months ? months[i] : i], &max_exists, "max temp");
        check_data_w_msg(month_temp_min[months ? months[i] : i], &min_exists, "min temp");
        check_data_w_msg(month_temp_avg[months ? months[i] : i], &avg_exists, "avg temp");
    
        // /* Если нет данных, то вывести сообщение об этом */
        if (!max_exists && !min_exists && !avg_exists)
        {
            printf("No data found.\n");
        }
        printf("\n");
    } 
}

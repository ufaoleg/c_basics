#include "utils.h"
#ifdef DEBUG
    #define DBG(msg, i, m) printf("debug: %s #%d\t D:%d/M:%d/Y:%d, temp: %.1f\n", msg, i, m.day, m.month, m.year, m.temp)
#else
    #define DBG(x,y,z)
#endif


int create_rand(int max_val, int min_val, int seed)
{
    srand(time(NULL) * seed);
    return (rand() % (max_val + 1 - min_val)) + min_val;
}

int generate_day_i(int seed)
{
    return create_rand(31, 1, seed);
}

int generate_month_i(int seed)
{
    return create_rand(12, 1, seed);
}

int generate_year_i(int seed)
{    
    return create_rand(2021, 2004, seed);
}

// https://stackoverflow.com/a/53370746
// the range is between [aMin, aMax]
// double f = (double)rand() / RAND_MAX;
// double result = aMin - f * aMin + f * aMax;

float generate_temp_f(int seed)
{
    srand(time(NULL)*seed);
    float f = (float)rand() / RAND_MAX;
    return -40 - f * (-40) + f * 40;
}

void generate_data_array(measure_t *arr_measures, int arr_size, bool verbose_flag)
{
    for (int i = 0; i < arr_size; i++)
    {   
        arr_measures[i].day = generate_day_i(i);
        arr_measures[i].month = generate_month_i(i);
        arr_measures[i].year = generate_year_i(i);
        arr_measures[i].temp = generate_temp_f(i);
        if (verbose_flag) 
            DBG("measure generated:", i+1, arr_measures[i]);
    }
}

int interactive_user(bool is_output_file_defined)
{
    if (!is_output_file_defined)
    {
        char answer[4];
        printf("Do you want to export data to text file? yes/no\n");
        scanf("%s", answer);
        if (str_compare(answer,"yes") == 0)
        {
            return 1;
        }
        else if (str_compare(answer, "no") == 0) return 0;
        else interactive_user(is_output_file_defined);
    }
    else return 0;
}

void write_to_file(measure_t *arr_measures, int arr_size, const char *file)
{
    FILE *f;

    f = fopen(file, "w");
    for (int i = 0; i < arr_size; i++)
    {
        fprintf(f, "%d;%d;%d;%.1f\n", arr_measures[i].day, arr_measures[i].month, arr_measures[i].year, arr_measures[i].temp);
    }

    fclose(f);    
}

int str_compare(const char *s1,const char *s2)
{
    int tmp1 = 0, tmp2 = 0;

    while (*s1++) tmp2 += *s1;
    while (*s2++) tmp1 += *s2;

    return tmp2-tmp1;
}


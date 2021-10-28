#include "structs.h"

int read_measurements_f_file(measure_t *measure, const char *file)
{
    FILE *f;
    int counter = 0;

    f = fopen(file, "r");
    if (!f) return -1;

    while (!feof(f))
    {
        int scans = fscanf(f, "%d;%d;%d;%f",
                        &measure[counter].day,
                        &measure[counter].month,
                        &measure[counter].year,
                        &measure[counter].temp
                        );
        if (scans != 4) break;
        counter++;
    }
    fclose(f);
    return counter;
}

void print_measurements(measure_t *measure, int measure_size)
{
    for (int i = 0; i < measure_size; i++)
    {
        printf("#%d\tD:%d M:%d, Y:%d, TEMP:%.1f\n",
                        i+1,
                        measure[i].day,
                        measure[i].month,
                        measure[i].year,
                        measure[i].temp
                        );
    }
}
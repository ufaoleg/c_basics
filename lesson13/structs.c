#include "structs.h"

measure_t *read_measurements_f_file(const char *file, int *array_size)
{
    FILE *f;
    int counter = 0;
    int array_counter = 0;
    int error_counter = 0;
    int max_arraysize = MAX_ARRSIZE;
    int scans;
    char chunk[128];

    // Store the chunks of text into a line buffer
    size_t len = sizeof(chunk);

    measure_t *measure = (measure_t *)malloc(sizeof(measure_t) * max_arraysize);
    char *line_buffer = (char *)malloc(sizeof(char) * len);
    // Empty the string
    line_buffer[0] = '\0';
    if (line_buffer == NULL) 
    {
        printf("Error allocating memory for line buffer.\n");
        return NULL;
    }
    if (measure == NULL)
    {
        printf("Error allocating memory for array size.\n");
        return NULL;
    }
    f = fopen(file, "r");
    if (!f) return NULL;
    /* fgets (char *str, int n, FILE *stream)
    str - указатель на массив, в который будет помещена считанная строка
    n - максимально допустимая длина считываемой строки
    stream - указатель на поток данных
    Функция считывает из потока данных строку, пока не встретится символ
    новая строка или не закончится файл или длиана строки превысит ограничение
    n -1 символ.
    После последнего прочитанного символа в массив заносится признак конца строки
    */
    // fgets(buffer, MAX_LEN, f); // чтение одной строки из файла
    int day, month, year, hour,minute,temp;

    while (fgets(chunk, sizeof(chunk), f) != NULL)
    {
        // Resize the line_buffer if necessary
        size_t len_used = strlen(line_buffer);
        size_t chunk_used = strlen(chunk);
        if (len - len_used < chunk_used) {
            len *= 2;
            if ((line_buffer = realloc(line_buffer, len)) == NULL) {
                printf("Error reallocating memory for line buffer.\n");
                free(line_buffer);
                break;
            }
        }

        if (array_counter == max_arraysize)
        {
            max_arraysize += MAX_ARRSIZE;
            measure = (measure_t *)realloc(measure, max_arraysize * sizeof(measure_t));
            if (measure == NULL) {
                printf("Error reallocating memory for array.\n");
                free(line_buffer);
                break;
            }
        }
        // Copy the chunk to the end of the line_buffer
        strncpy(line_buffer + len_used, chunk, len-len_used);
        len_used += chunk_used;

        // Check if line contains '\n', if yes process the line of text
        if(line_buffer[len_used - 1] == '\n') {
            if (6 == sscanf(line_buffer, "%d;%d;%d;%d;%d;%d",
                        &measure[array_counter].year,
                        &measure[array_counter].month,
                        &measure[array_counter].day,
                        &measure[array_counter].hour,
                        &measure[array_counter].minute,
                        &measure[array_counter].temp
                        ))
                        {
                            array_counter++;
                        }
            else
            {
                #ifdef DEBUG
                    printf("#%d row is corrupt! Skipped.\n", counter);
                #endif
                error_counter++;
            }
            // Empty the line buffer
            line_buffer[0] = '\0';
            counter++;
        if (feof(f)) break;
        }
    }    
    fclose(f);
    free(line_buffer);
    *array_size = array_counter;
    #ifndef DEBUG
        if (error_counter > 0) 
            printf("WARNING! Input data have %d error(s).\n", error_counter);
            printf("To more information make app with -DDEBUG flag.\n\n");
    #endif
    return measure;
}

void print_measurements(measure_t *measure, int measure_size)
{
    for (int i = 0; i < measure_size; i++)
    {
        printf("#%d\tY:%d M:%d, D:%d, (%d:%d), TEMP:%d\n",
                        i+1,
                        measure[i].year,
                        measure[i].month,
                        measure[i].day,
                        measure[i].hour,
                        measure[i].minute,
                        measure[i].temp
                        );
    }
}

char *parse_month(int month)
{
    switch (month)
    {
        case 1:
            return "JANUARY";
        case 2:
            return "FEBRUARY";
        case 3:
            return "MARCH";
        case 4:
            return "APRIL";
        case 5:
            return "MAY";
        case 6:
            return "JUNE";
        case 7:
            return "JULY";
        case 8:
            return "AUGUST";
        case 9:
            return "SEPTEMBER";
        case 10:
            return "OCTOBER";
        case 11:
            return "NOVEMBER";
        case 12:
            return "DECEMBER";
    }
     
}
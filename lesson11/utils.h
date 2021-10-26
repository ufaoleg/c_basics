#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>

void mycopy(char *source, char *destination);

/* Чтение из файла */
int read_f_file(void *ptr, size_t *bytescount, FILE *f_src);

// void read_f_file(void *ptr, int bytescount, const char *filename);
/* Запись в файл*/
void write_to_file(const void *ptr, size_t bytescount, FILE *f_dest);

#endif
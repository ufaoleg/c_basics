#include "utils.h"
#include <stdlib.h>

void mycopy(char *source, char *destination)
{
    int buf_size = 4096;
    char buffer[buf_size];
    FILE *file_src, *file_dest;
    file_src = fopen(source, "rb"); // source file
    file_dest = fopen(destination, "wb"); //destination file
    size_t result = 0; 

    do {    
        result = fread(buffer, 1, sizeof(buffer), file_src);
        if (result <= 0) break;
        printf("read %lu bytes\n", result);
        write_to_file(buffer, result, file_dest);
    }
    while (result == sizeof(buffer));

    fclose(file_src);
    fclose(file_dest);
    printf("File \"%s\" copied.\n", destination);
}

// size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
// The function fread() reads nmemb items of data, each size bytes long,
// from the stream pointed to by stream, storing them at the location
// give by ptr.
// ptr - the array where the elements will be stored;
// size - the size of each elements in bytes;
// nmemb - the number of elements to read;
// stream - the stream to read;
// returns - the fread function returns the number of elements read.
// the fread function will return zero if nmemb is zero or size is zero.
int read_f_file(void *ptr, size_t *bytescount, FILE *f_src)
{
    if (!f_src) {
        printf("Error load read file\n");
        return -1;
    };
    *bytescount = fread(ptr, 1, sizeof(ptr), f_src);
    if (*bytescount <= 0) {
        printf("bytescount is %zd\n", *bytescount);
        return -1;
        }
    printf("read %zu bytes\n", *bytescount);
    return 0;
}

// size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
// The function fwrite() writes nmemb items of data, each size bytes long,
// to the stream pointed to by stream, obtaining them from the location
// given by ptr.
void write_to_file(const void *ptr, size_t bytescount, FILE *f_dest)
{
    if (!f_dest) {
        printf("Error writing\n");
    }
    if (fwrite(ptr, 1, bytescount, f_dest) != bytescount)
    {
        printf("fwrite failed!\n");
    }
    printf("write %ld bytes\n", bytescount);
}

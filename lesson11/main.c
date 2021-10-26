#include <stdio.h>
#include "utils.h"

/*
Задание1:
Копирование файлов. Режим работы - двоичный.
Пользователь указывает имя файла для копирования, и имя файла целевого.
Происходит копирование(как утилита/команда cp)

например:
./mycp file1 file2

Задание2:
Рекурсивный вывод файлов в директории.
Вывести информацию о файлах в директории(и из всех дочерних директорий), указанной пользователем либо через аргументы командной строки(argc,argv), либо через getcwd() либо через scanf()
Аналогия: команда ls -r
например:
./myls /home/user

Для программы сделать Makefile
Программа должна быть модульной
*/

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("mycp: missing file operand\n");
        return -1;
    }
    else if (argc < 3)
    {
        printf("mycp: missing destination file operand after %s\n", argv[1]);
        return -1;
    }
    else if (argc == 3) {
        
        mycopy(argv[1], argv[2]);
    }

    return 0;
}

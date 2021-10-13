#include <stdio.h>
#include <stdlib.h> // rand
#include <time.h> // time

/*
Реализовать алгоритм сортировки массива(любой на ваше усмотрение)
https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B8
И продемонстрировать его работу.
Исходные данные для массива либо вводятся вручную, либо берутся случайные значения через rand()
*/

/* сортировка пузырьком - простейший, эффективен лишь для небольших массивов O(n^2) */
void bubble_sort(int array[], int N);
/* поменять местами два числа */
void swap(int *a, int *b);
/* вывод массива в удобном виде */
void print_array(int array[], int N);
/* заполнить массив случайными числами */
void fill_array_random(int array[], int N);
/* пользователь вводит желаемую длину массива */
int get_user_input(void);

int main(void)
{
    int array_length = get_user_input();

    int array[array_length];
    printf("Original random array: \n");
    fill_array_random(array, array_length);
    print_array(array, array_length);

    bubble_sort(array, array_length);
    printf("Sorted array: \n");
    print_array(array, array_length);
    return 0;
}

// 5 1 4 2 8

void bubble_sort(int array[], int N)
{
    for (int i = 0; i < N-1; i++)
    {
        int flag = 0;
        for (int j = 0; j < N-i-1;j++)
        {
            if (array[j] > array[j+1])
            {
                swap(&array[j],&array[j+1]);
                flag = 1;
            }
        }
        // если элементы не меняются местами
        // во вложенном цикле, то сортировка закончена
        if (flag == 0) break;
    }
}

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void print_array(int array[], int N)
{
    for (int i = 0; i<N; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void fill_array_random(int array[], int N)
{
    srand(time(NULL));

    for (int i=0;i<N;i++)
    {
        array[i]=rand() % 100 - 50;
    }
}

int get_user_input(void) {
    int input, rc;

    printf("Enter length of array to be sorted: ");
    rc = scanf("%d", &input);

    return input;
}
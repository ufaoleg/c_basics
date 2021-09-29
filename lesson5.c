#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Распечатать первые n простых чисел (просто число X - это такое число X>=2 и делится только на 1 и на себя)
Пример:
Пользователь вводит 5 - значит надо вывести первые 5 простых чисел
2 3 5 7 11
*/

int get_user_input(void);
bool is_value_prime(int);
void sequence_of_prime(int);

int main (void)
{
    int from_user = get_user_input();
    sequence_of_prime(from_user);

    return 0;
}

// Обработчик ввода пользователя
int get_user_input(void) {
    int input, rc;

    printf("Please enter positive int number:\n");
    rc = scanf("%d", &input);

    return input;
}

// Вывод последовательности N простых чисел
void sequence_of_prime(int arg) {
    int counter = 0;
    if (arg == 1) {
        printf("\"%d\" is prime number", arg);
    }
    else if (arg > 1) {
        printf("A sequence of \"%d\" prime numbers: ", arg);
        for(int i = 2; counter < arg; i++) {
                if (is_value_prime(i)) {                
                    printf("%d ", i);
                    counter++;
                }
        }
    }
    else {
        printf("Wrong number!");
    }
    printf("\n");
}


// Функция определяет простое ли число
bool is_value_prime(int arg) {

    for (int i = 2; i < arg; i++) {
        if ((arg % i) == 0) {
            return false;
        }
    }

    return true;
}


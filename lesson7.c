#include <stdio.h>
#include <stdbool.h>

/*
Программа "стрельба в мишень"

Пользователь вводит с клавиатуры 3 числа типа float(X, Y, Radius)

Первая функция вида
bool get_user_input(float *X, float *Y, float *R)
считывает с клавиатуры значения координат X,Y и радиуса, и проводит валидацию входных значений.(количество успешных преобразований от функции scanf, неотрицательный и ненулевой радиус и так далее)
Если происходит ошибка - функция возвращает false. В этом случае программа с ошибкой завершается.

Вторая функция вида
bool is_target_hit(float X, float Y, float R)
проверяет, попал ли пользователь в мишень. Формула X*X + Y*Y < R*R
Результат выводится на экран(printf)
*/

/*
Функция считывает с клавиатуры значения координат X,Y и радиуса R
и проводит валидацию входных значений
*/
bool get_user_input(float *X, float *Y, float *R);

/*
Функция проверяет, попал ли пользователь в мишень
*/
bool is_target_hit(float X, float Y, float R);

int main(void)
{
    float X,Y,Radius;
    if (!get_user_input(&X, &Y, &Radius)) 
    {
        printf("Error!\n");
        return -1;
    }
    else {
        //printf("X:%f,Y:%f,R:%f\n",X,Y,R);
        is_target_hit(X, Y, Radius);
    }
    return 0;
}

bool get_user_input(float *X, float *Y, float *R)
{
    int retcode = scanf("%f%f%f", X,Y,R);
    if (retcode == 3)
    {
        if (*R > 0)
        {
            return true;
        }
        printf("Radius should be positive value!\n");
        return false;
    }
    return false;

}

bool is_target_hit(float X, float Y, float R)
{
    if (X*X + Y*Y < R*R)
    {
        printf("HIT!\n");
        return true;
    }
    else if (X*X + Y*Y == R*R)
    {
        printf("Almost got it, but no!\n");
        return false;
    }
    printf("You missed! Try again!\n");
    return false;
}

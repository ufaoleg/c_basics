#include <stdio.h>

/*
Пользователь вводит строку, состоящую из десятичных цифр, английских букв, символов пробела и так далее.
Вычислить абсолютное и процентное соотношение символов:

1) цифр
2) английских букв верхнего регистра
3) английских букв нижнего регистра
4) пробелов

Пример:

Вводим "123 456 abc DEF ++"
общая длина строки - 18 символов
из них цифр 6, то есть примерно 33% ((float)6 / (float)18) * 100
пробелов 4
и так далее.
*/

void get_count(void);
void report(int total, int digits, int uppercase, int lowercase, int spaces, int symbols);
int get_percent(int a, int total);

int main(void)
{
    printf("Enter digits, chars:\n");
    get_count();
    return 0;
}

void get_count(void)
{
    char c;
    int digits_sum = 0;
    int uppercase_sum = 0;
    int lowercase_sum = 0;
    int spaces_sum = 0;
    int symbols_sum = 0;
    int total_sum = 0;
    while((c = getchar()) != '\n') {
        if (c >= 'a' && c <= 'z') {
            lowercase_sum += 1;
        }
        else if (c >= 'A' && c <= 'Z') {
            uppercase_sum += 1;
        }
        else if (c >= '0' && c <= '9') {
            digits_sum += 1;
        }
        else if (c == 32) {
            spaces_sum += 1;
        }
        else symbols_sum +=1;
        total_sum += 1;
    }
    report(total_sum, digits_sum, uppercase_sum, lowercase_sum, spaces_sum, symbols_sum);
}

int get_percent(int a, int total)
{
    if (a == 0) return 0;
    int p = ((float)a / (float)total) * 100;
    printf(", (~%d%%)\n", p);
    return p;
}

void report(int total, int digits, int uppercase, int lowercase, int spaces, int symbols)
{
    printf("====\n");
    printf("Total length: %d, where:\n", total);
    printf("\tsum of digits: %d", digits);
    get_percent(digits, total);
    printf("\tsum of uppercase chars: %d", uppercase);
    get_percent(uppercase, total);
    printf("\tsum of lowercase chars: %d", lowercase);
    get_percent(lowercase, total);
    printf("\tsum of spaces: %d", spaces);
    get_percent(spaces, total);
    printf("\tsum of symbols: %d", symbols);
    get_percent(symbols, total);
    printf("====\n");
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define ROW 9
#define COL 9
#define V_ROW 5

int multiply(int row, int col);
int pattern_value(int row, int col);
int sum_digits(long long number);

int main(void)
{
    int row, col;
    long long number;
    int sum;
    char answer;

    setlocale(LC_ALL, "");

    // Задание 1.1. Таблица умножения
    printf("--- Задание 1.1. Таблица умножения ---\n");

    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= COL; col++)
        {
            printf("%5d", multiply(row, col));
        }
        printf("\n");
    }

    printf("\n");

    // Задание 1.2. Левый нижний треугольник
    printf("--- Задание 1.2. Левый нижний треугольник ---\n");

    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= row; col++)
        {
            printf("%5d", multiply(row, col));
        }
        printf("\n");
    }

    printf("\n");

    // Задание 1.3. Вариант 6
    printf("--- Задание 1.3. Вариант 6 ---\n");

    for (row = 1; row <= V_ROW; row++)
    {
        for (col = 1; col <= row; col++)
        {
            printf("%3d", pattern_value(row, col));
        }
        printf("\n");
    }

    printf("\n");

    // Задание 2. Вариант 6
    printf("--- Задание 2. Вариант 6 ---\n");

    do
    {
        printf("Введите целое число: ");

        if (scanf("%lld", &number) != 1)
        {
            printf("Ошибка ввода.\n");
            return 1;
        }

        sum = sum_digits(number);

        printf("Сумма цифр, больших или равных 7: %d\n", sum);

        printf("Продолжить? (Да - y, нет - n): ");

        if (scanf(" %c", &answer) != 1)
        {
            printf("Ошибка ввода.\n");
            return 1;
        }

    } while (answer == 'y' || answer == 'Y');

    return 0;
}

// Вычисление произведения строки и столбца
int multiply(int row, int col)
{
    int result;

    result = row * col;

    return result;
}

// Определение значения для таблицы варианта 6
int pattern_value(int row, int col)
{
    int value;

    if (col <= row)
    {
        value = row;
    }
    else
    {
        value = 0;
    }

    return value;
}

// Вычисление суммы цифр, больших или равных 7
int sum_digits(long long number)
{
    int digit;
    int sum = 0;

    do
    {
        digit = (int)(number % 10);

        if (digit < 0)
        {
            digit = -digit;
        }

        if (digit >= 7)
        {
            sum += digit;
        }

        number /= 10;

    } while (number != 0);

    return sum;
}
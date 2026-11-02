#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main(void)
{
    int row, col;
    long long number;
    int digit, sum;
    char answer;

    setlocale(LC_ALL, "");

    // Задание 1.1. Таблица умножения
    printf("--- Задание 1.1. Таблица умножения ---\n");

    for (row = 1; row <= 9; row++)
    {
        for (col = 1; col <= 9; col++)
        {
            printf("%5d", row * col);
        }
        printf("\n");
    }

    printf("\n");

    // Задание 1.2. Левый нижний треугольник
    printf("--- Задание 1.2. Левый нижний треугольник ---\n");

    for (row = 1; row <= 9; row++)
    {
        for (col = 1; col <= row; col++)
        {
            printf("%5d", row * col);
        }
        printf("\n");
    }

    printf("\n");

    // Задание 1.3. Вариант 6
    printf("--- Задание 1.3. Вариант 6 ---\n");

    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= row; col++)
        {
            printf("%3d", row);
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

        sum = 0;

        do
        {
            digit = number % 10;

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
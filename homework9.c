#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

int main(void)
{
    int row, col;
    int a;
    char symbol;
    char answer;

    setlocale(LC_ALL, "");

    // Задание 3. Вариант 7
    printf("--- Домашнее задание. Вариант 7 ---\n");

    do
    {
        printf("Введите символ для построения фигуры: ");

        if (scanf(" %c", &symbol) != 1)
        {
            printf("Ошибка ввода.\n");
            return 1;
        }

        printf("Введите размер стороны: ");

        if (scanf("%d", &a) != 1)
        {
            printf("Ошибка ввода.\n");
            return 1;
        }

        if (a < 2)
        {
            printf("Размер стороны должен быть не меньше 2.\n");
        }
        else
        {
            printf("Равносторонний треугольник:\n");

            for (row = 1; row <= a; row++)
            {
                for (col = 1; col <= a - row; col++)
                {
                    printf(" ");
                }

                for (col = 1; col <= 2 * row - 1; col++)
                {
                    if (col == 1 || col == 2 * row - 1 || row == a)
                    {
                        printf("%c", symbol);
                    }
                    else
                    {
                        printf(" ");
                    }
                }

                printf("\n");
            }
        }

        printf("\nПродолжить рисование? (Да - y, нет - n): ");

        if (scanf(" %c", &answer) != 1)
        {
            printf("Ошибка ввода.\n");
            return 1;
        }

    } while (answer == 'y' || answer == 'Y');

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

char triangle_symbol(int row, int col, int height, char symbol);
void draw_triangle(int height, char symbol);

int main(void)
{
    char symbol;
    int height;
    int answer;

    setlocale(LC_ALL, "");

    // Задание 3. Вариант 7

    do
    {
        printf("Введите символ для построения фигуры: ");

        if (scanf(" %c", &symbol) != 1)
        {
            printf("Ошибка ввода.\n");
            return 1;
        }

        printf("Введите размер стороны: ");

        if (scanf("%d", &height) != 1)
        {
            printf("Ошибка ввода.\n");
            return 1;
        }

        if (height < 2)
        {
            printf("Ошибка: размер стороны должен быть не меньше 2.\n");
        }
        else
        {
            printf("Равносторонний треугольник:\n\n");

            draw_triangle(height, symbol);
        }

        printf("\nПродолжить? (Да - введите любое число, Нет - введите 0): ");

        if (scanf("%d", &answer) != 1)
        {
            printf("Ошибка ввода.\n");
            return 1;
        }

    } while (answer != 0);

    return 0;
}

// Определение символа для заданной позиции
char triangle_symbol(int row, int col, int height, char symbol)
{
    char result;

    if (col == 1 || col == 2 * row - 1 || row == height)
    {
        result = symbol;
    }
    else
    {
        result = ' ';
    }

    return result;
}

// Построение равностороннего треугольника
void draw_triangle(int height, char symbol)
{
    int row, col;
    char c;

    for (row = 1; row <= height; row++)
    {
        for (col = 1; col <= height - row; col++)
        {
            putchar(' ');
        }

        for (col = 1; col <= 2 * row - 1; col++)
        {
            c = triangle_symbol(row, col, height, symbol);
            putchar(c);
        }

        printf("\n");
    }
}
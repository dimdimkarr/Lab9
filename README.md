# Lab9
## Условие задачи  
Задача 1. Используя циклы, выполнить следующие задания:   

1.1. Вывести таблицу умножения от 1 до 9.  

1.2. Вывести левую нижнюю треугольную часть таблицы умножения.  

1.3. Выполнить задание по варианту 6: вывести последовательность чисел, в которой каждая следующая строка содержит соответствующее количество повторений числа.  

Задача 2. Вариант 6. Написать программу, которая вычисляет сумму цифр введённого целого числа, больших или равных 7. Предусмотреть возможность повторного выполнения программы по желанию пользователя. Использовать цикл с постусловием do-while.  
 

## Реализация программы  
```c
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

    setlocale(LC_ALL, "Russian");

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
```
## Пример работы программы  

Задание 1.1. Таблица умножения  

    1    2    3    4    5    6    7    8    9  
    2    4    6    8   10   12   14   16   18  
    3    6    9   12   15   18   21   24   27  
    4    8   12   16   20   24   28   32   36  
    5   10   15   20   25   30   35   40   45  
    6   12   18   24   30   36   42   48   54  
    7   14   21   28   35   42   49   56   63  
    8   16   24   32   40   48   56   64   72  
    9   18   27   36   45   54   63   72   81  

Задание 1.2. Левый нижний треугольник  

    1  
    2    4  
    3    6    9  
    4    8   12   16  
    5   10   15   20   25  
    6   12   18   24   30   36  
    7   14   21   28   35   42   49    
    8   16   24   32   40   48   56   64  
    9   18   27   36   45   54   63   72   81  

Задание 1.3. Вариант 6  

  1  
  2  2  
  3  3  3  
  4  4  4  4  
  5  5  5  5  5  

Задание 2. Вариант 6  
Введите целое число: 178923  
Сумма цифр, больших или равных 7: 24  
Продолжить? (Да - y, нет - n): n  

# Домашнее задание. Вариант 7  

## Условие задачи  
Задача 3. Вариант 7. Написать программу для построения равностороннего треугольника из заданного пользователем символа. Пользователь вводит символ и размер стороны. Треугольник должен быть контурным. Предусмотреть возможность повторного построения фигуры по желанию пользователя.  

## Реализация программы
```c
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

    setlocale(LC_ALL, "Russian");

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
```
## Пример работы программы  

Домашнее задание. Вариант 7  
Введите символ для построения фигуры: *  
Введите размер стороны: 5  
Равносторонний треугольник:  
    *  
   * *  
  *   *  
 *     *  
*********  
Продолжить рисование? (Да - y, нет - n): n  

## Информация о разработчике
Жукова Дарья, бИД-261

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

/**
* @brief Считывает вещественное значение
* @return Возвращает вещественное значение
*/
double input(void);

/**
* @brief Проверяет правильность введенных значений интервала
* @param start начало интервала
* @param end конец интервала
* @return Возвращает ошибку, если введен некорректный интервал
*/
void check_interval(const double start, const double end);

/**
* @brief Проверяет правильность введенного значения шага
* @param step величина шага
* @return Возвращает ошибку, если введен некорректный шаг
*/
void check_step(const double step);

/**
* @brief Проверят правильность значения x
* @param x переменная x
* @return Возвращает True в случае успеха, иначе - False
*/
bool check_x_value(double x);

/**
* @brief Вызвает функцию
* @param x значение переменной x
* @return Возвращает значение функции если нет деления на нуль, в ином случае вызывает ошибку
*/
double getFunction(double x);

/**
* @brief Точка входа в программу
* @return Возвращает 0 в случае успеха
*/
int main(void)
{
	printf("Введите значение интервала: ");
	const double start = input();
	const double end = input();
	check_interval(start, end);
	printf("Введите значение шага: ");
	const double step = input();
	check_step(step);
	for (double x = start; x < end+step; x += step)
	{
		if (!check_x_value(x))
		{
			printf("нет значения!");
		}
		else
		{
			printf("x = %.3lf, y = %.3lf\n", x, getFunction(x));
		}
	}
	return 0;
}

double input()
{
	double value = 0.0;
	int result = scanf("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Ошибка ввода!");
		exit(EXIT_FAILURE);
	}
	return value;
}

void check_interval(const double start, const double end)
{
	if (end - start < DBL_EPSILON)
	{
		errno = EIO;
		perror("Ошибка ввода значения интервала!");
		exit(EXIT_FAILURE);
	}
}

void check_step(const double step)
{
	if (step <= DBL_EPSILON)
	{
		errno = EIO;
		perror("Ошибка ввода значения шага!");
		exit(EXIT_FAILURE);
	}
}

bool check_x_value(double x)
{
	return x > DBL_EPSILON;
}

double getFunction(double x)
{

	return 3*x - 4*log(x) - 5 ;
}

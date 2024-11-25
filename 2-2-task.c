#include <stdio.h>
#include <stdlib.h>			
#include <math.h>
#include <errno.h>

/**
 * @brief решение первого примера
 * @return возвращает ответ первого примера
 */
double geta(const double a, const double x);
 
/**
 * @brief считывает число
 * @return число
 */
double getb(const double a, const double x);

/**
 * @brief считывает число
 * @return число
 */
double input(void);

/** 
 * @brief точка входа в программу
 * @return 0, в случае успеха 
 */
int main(void)
{
    const double a = 2.5;
    const double x = input();
    if (x > a) {
        printf("%lf", geta(a, x));
    }
    else {
        printf("%lf", getb(a, x));
    }
    return 0;
}

double input(void)
{
    double value = 0.0;
    int result = scanf("%lf", &value);
    if (result != 1) { 
        errno = EIO;
        printf("Не удалось считать число");
        exit(EXIT_FAILURE);
    } 
    return value;
}

double geta(const double a, const double x)
{
    return (x * pow(sin(x), 2));
}

double getb(const double a, const double x)
{
    return (x * pow(cos(x), 2));
}

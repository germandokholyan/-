#include <stdio.h>
#include <math.h>

/**
 * @brief считывает вещественное число 
 * @return вещественное число
*/
double Input(void);

/**
 * @brief вычисляет расстояние между двумя точками
 * @param x1 - координата x первой точки
 * @param y1 - координата y первой точки
 * @param x2 - координата x второй точки
 * @param y2 - координата y второй точки
 * @return рассчитанное расстояние
 */
double Getdistance(const double x1, const double y1, const double x2, const double y2);

/**
 * @brief Точка входа в программу.
 * @return 0 в случае выполнений без ошибок
*/
int main(void) 
{
    puts("введите точку х1");
    double x1 = Input();
    puts("введите точку y1");
    double y1 = Input();
    puts("введите точку х2");
    double x2 = Input();
    puts("введите точку y2");
    double y2 = Input();
    printf("расстояние между координатами %lf\n", Getdistance(x1, y1, x2, y2));
    return 0;
}

double Getdistance(const double x1, const double y1, const double x2, const double y2) 
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double Input(void) 
{
    double value = 0.0;
    scanf("%lf", &value);
    return value;
}

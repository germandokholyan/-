#include <stdio.h>
#include <math.h>

/**
 * @brief рассчитывает выражение а
 * @param x - значение параметра х
 * @param y - значение параметра у
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double geta(const double x, const double y, const double z, const double sum, const double tg);

/**
 * @brief рассчитывает выражение b
 * @param x - значение параметра х
 * @param y - значение параметра у
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getb(const double x, const double y, const double z, const double sum, const double tg);
 
/**
 * @brief точка входа в программу
 * @return 0,случае успеха
 */
int main() 
{
    const double x = 0.61, y = 3.4, z = 16.5;
    const double sum = x + y;
    const double tg = tan(pow(sum, 2));
    printf("x = %f", x);
    printf("y = %f", y);
    printf("z = %f\n", z);
    printf("a = %f\n", geta(x, y, z, sum, tg));
    printf("b = %f\n", getb(x, y, z, sum, tg));
    return 0;
}
double geta(const double x, const double y, const double z, const double sum, const double tg)
{
    return pow(x, 3) * pow(tg, 2) + (z / sqrt(sum));
}

double getb(const double x, const double y, const double z, const double sum, const double tg)
{
    return (y * pow(x, 2) - z) / (exp(z * x) - 1);
}

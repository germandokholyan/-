#include <stdio.h>
#include <math.h>

/**
 * @brief рассчитывает выражение а
 * @param x - значение параметра х
 * @param y - значение параметра у
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double geta(const double x, const double y, const double z);

/**
 * @brief рассчитывает выражение b
 * @param x - значение параметра х
 * @param y - значение параметра у
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getb(const double x, const double y, const double z);
 
/**
 * @brief точка входа в программу
 * @return 0,случае успеха
 */
int main(void) 
{
    const double x = 0.61, y = 3.4, z = 16.5;
    printf("x = %f", x);
    printf("y = %f", y);
    printf("z = %f\n", z);
    printf("a = %f\n", geta(x, y, z));
    printf("b = %f\n", getb(x, y, z));
    return 0;
}
double geta(const double x, const double y, const double z)
{
    return pow(x, 3) * pow(tan(pow(x + y, 2)), 2) + (z / sqrt(x + y));
}

double getb(const double x, const double y, const double z)
{
    return (y * pow(x, 2) - z) / (exp(z * x) - 1);
}

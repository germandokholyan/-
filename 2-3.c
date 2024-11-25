#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>

/**
 * @brief Проверка, лежат ли три точки на одной прямой
 * @return 1, если лежат; 0, если нет
 */
double geta(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3);

/**
 * @brief Вычисляет угол в градусах между отрезками AB и BC
 * @return угол B
 */
double getb(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3);

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
    double x1, y1, x2, y2, x3, y3; 
    printf("введите координаты точки А (х1, у1): ");
    x1 = input(), y1 = input();
    printf("введите координаты точки B (x2, у2): ");
    x2 = input(), y2 = input();
    printf("введите координаты точки А (х3, у3): ");
    x3 = input(), y3 = input();
    if (geta(x1, y1, x2, y2, x3, y3)){
        printf("Точки лежат на 1 прямой");
    } else {
        double anluck = getb(x1, y1, x2, y2, x3, y3);
        printf("Точки не лежат на 1 прямой, угол В равен: %.2lf градусов ", anluck);
    }
    return 0;
}



double geta(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
{
    return (x3 - x1) * (y2 - y1) == (y3 - y1) * (x2 - x1);
}

double getb(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
{
    double ab_x = x2 - x1;
    double ab_y = y2 - y1;
    double bc_x = x3 - x2;
    double bc_y = y3 - y2;
    double cosinus = (ab_x * bc_x + ab_y * bc_y)/((sqrt(pow(ab_x, 2) + pow(ab_y, 2))) * (sqrt(pow(bc_x, 2) + pow(bc_y, 2))));
    double corner = acos(cosinus);
    return corner; 
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

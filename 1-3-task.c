#include <stdio.h>

/**
 * @brief Считывает вещественное число
 * @return вещественное число
 */
double Input(void);

/**
 * @brief Рассчитывает давление
 * @param m - масса плиты в кг
 * @param S - площадь опоры в м²
 * @return рассчитанное давление 
 */
double press(const double m, const double S);

/**
  * @brief Точка входа в программу
  * @return 0 если программа работает без ошибок
  */
int main(void) {
    puts("введите массу бетонной плиты(m) в кг");
    double m = Input();
    puts("введите площадь опоры (S) в м^2");
    double S = Input();
    printf("Давление, производимое плитой: %lf Па\n", press(m, S));
    return 0;
}
double press(const double m, const double S) {
    const double g = 9.81;
    return (m * g) / S; 
}
double Input(void) {
    double value = 0.0;
    scanf("%lf", &value);
    return value;
}

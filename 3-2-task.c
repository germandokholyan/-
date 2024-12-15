#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <float.h>

/**
* @brief Считывает введенное значение 
* @return Возвращает считанное значение 
*/ 
double input(void); 

/** 
* @brief Считывает введеное целое значение 
* @return Возвращает считанное значение 
*/ 
int input_int(void); 

/** 
* @brief Проверяет неотрицательность введенного значения 
* @param quantity введенное значение 
* @return Возвращает ошибку, если значение меньше нуля 
*/ 
void check_quantity(const int quantity); 

/** 
 * @brief Проверяет неотрицательность вещественного значения 
 * @param value введеное значение  
 * @return Возвращает ошибку, если введеное значение не положительно 
 */ 
void check_value(const double value); 

/** 
* @brief Рассчитывает значение следующего элемента последовательности 
* @param k текущий индекс последовательности 
* @return Возвращает значение следующего элемента последовательности 
*/ 
double next_element(const int k); 

/** 
* @brief Рассчитывает значение суммы n членов 
* @param n Количество членов последовательности 
* @return Возвращает значение суммы n членов последовательности 
*/ 
double get_n_sum(const int n); 

/**
* @brief Рассчитывает значение суммы всех членов последовательности, не меньших заданного числа e
* @param e Заданное число
* @return Возвращает значение суммы всех членов последовательности
*/
double get_sum_not_less_than_e(const double e);

/** 
* @brief Точка входа в программу 
* @return В случае успеха, возвращает 0 
*/ 
int main(void) 
{ 
    printf("Введите число n:\n"); 
    const int n = input_int(); 
    printf("Введите значение e:\n"); 
    const double e = input(); 
    printf("Сумма N элементов = %.7lf\n", get_n_sum(n));
    printf("Сумма всех элементов не менее e = %.3lf\n", get_sum_not_less_than_e(e));
    return 0; 
} 

double input(void) 
{ 
    double value = 0.0; 
    int result = scanf("%lf", &value); 
    if (result != 1) 
    { 
        errno = EIO; 
        perror("ошибка ввода!"); 
        exit(EXIT_FAILURE); 
    } 
    check_value(value); 
    return value; 
} 

int input_int(void) 
{ 
    int quantity = 0; 
    int result = scanf("%d", &quantity); 
    if (result != 1) 
    { 
        errno = EIO; 
        perror("ошибка ввода!"); 
        exit(EXIT_FAILURE); 
    } 
    check_quantity(quantity); 
    return quantity; 
} 

void check_quantity(const int quantity) 
{ 
    if (quantity < 0) 
    { 
        errno = EIO; 
        perror("Значение не может быть ниже нуля!"); 
        exit(EXIT_FAILURE); 
    } 
} 

void check_value(const double value) 
{ 
    if(value < 0) 
    { 
        errno = EIO; 
        perror("Значение не может быть ниже нуля!"); 
        exit(EXIT_FAILURE); 
    } 
} 

double next_element(const int k) 
{ 
    return -1 * ((double)k + 1) / ((double)k + 5); 
} 

double get_n_sum(const int n) 
{ 
    double element = -1.0 / 120; // Первый член последовательности
    double sum = element; 

    for (int k = 1; k < n; ++k) 
    { 
        element *= next_element(k); 
        sum += element; 
    } 

    return sum; 
}

double get_sum_not_less_than_e(const double e)
{
    double element = -1.0 / 120; // Первый член последовательности
    double sum = 0;
    int k = 0; 

    while (fabs(element) >= e + DBL_EPSILON) 
    {
        sum += element;
        k++; 
        element *= next_element(k); 
    }

    return sum;
}

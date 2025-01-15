#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>
/**
* @brief Считывает введеное значение
* @return Возвращает введенное значение
*/
int input(void);

/**
 * @brief Создает массив
 * @param n размер массива
 * @return Возвращает массив с n элементами
 */
int* get_array(const size_t n);

/**
 * @brief Проверяет введенное число на неотрицательность
 * @param value вводимое число
 * @return Возвращает ошибку, если число отрицательно или равно 0
 */
int no_negativ_input(void);

/**
* @brief Проверяет массив
* @param array массив
* @return возвращает ошибку, в случае недостатка памяти для массива
*/
void check_array(const int* array);

/**
 * @brief Копирует исходный массив
 * @param array исходный массив
 * @param n число элементов массива
 * @return Возвращает скопированный массив
 */
int* copy(const int* const array, const size_t n);

/**
* @brief Заполняет массив случайными числами
* @param array массив
* @param n количество элементов в массиве
* @param min начало диапазона
* @param max конец диапазона
* @return возвращает массив, заполненный случайными числами
*/
void fill_array_random(int* array, const size_t n, const int min, const int max);

/**
* @brief Заполнение массива при помощи ввода элементов с клавиатуры
* @param array массив
* @param n количество элементов в массиве
* @return возвращает массив, заполненный числами, введеными вручную
*/
void fill_array_manual(int* array, const size_t n);

/**
 * @brief Выводит исходный массив
 * @param array массив
 * @param n количество элементов в массиве
 * @return Возвращает вывод исходного массива
*/
void print_array(const int* array, const size_t n);

int min_elem_index(const int* array, int n);

int average_meaning(const int* array, int n);

void replace_min_and_average(int* array, int n);

int contains_five(int number);

int* array_no_five(const int* array, int n, int* m);

int* array_a_c(const int* array, int n);



/**
* @param random заполнение массива случайными числами
* @param manual заполнение массива пользователем
*/
enum request
{
    Random, manual
};

/**
* @brief Точка входа в программу
* @return Возвращает 0 в случае успеха
*/
int main(void)
{
    system("chcp 1251");
    printf("Введите размер массива: ");
    size_t n = no_negativ_input();
    int* array = get_array(n);

    printf("Random - %d\n", Random);
    printf("Manual - %d\n", manual);

    int choice = input();
    switch (choice)
    {
    case Random:
        srand(time(0));  // Инициализация генератора случайных чисел
        printf("введите минимальное значение интервала \n");
        const int min = input();
        printf("введите максимальное значение интервала \n");
        const int max = input();
        fill_array_random(array, n, min, max);
        break;
    case manual:
        fill_array_manual(array, n);
        break;
    default:
        errno = ERANGE;
        perror("Function does not exist\n");
        exit(EXIT_FAILURE);
        break;
    }

    printf("Содержимое массива: ");
    print_array(array, n);

    int* clon_array = copy(array, n);
    replace_min_and_average(clon_array, n);

    printf("массив после замены минимального элемента на средний:\n");
    print_array(clon_array, n);
    free(clon_array);
    printf("Массив без эллементов с цифрой 5:");
    int m = 0;
    int* cloned_array = copy(array, n);
    int* arr_no_five = array_no_five(cloned_array, n, &m);
    print_array(arr_no_five, m);
    free(arr_no_five);
    printf("массив А после перехода в массив С:");
    int* array_c = array_a_c(cloned_array, n);
    print_array(array_c, n);
}
int input(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1)
    {
        errno = EIO;
        perror("ошибка ввода");
        exit(EXIT_FAILURE);
    }
    return value;
}

int* get_array(const size_t n)
{
    int* array = (int*)malloc(n * sizeof(int));
    return array;
}
int no_negativ_input(void)
{
    int value = input();
    if (value <= 0)
    {
        errno = EINVAL;
        perror("Значение должно быть больше или равно нулю");
        exit(EXIT_FAILURE);
    }
    return value;
}

void check_array(const int* array)
{
    if (array == NULL)
    {
        errno = ENOMEM;
        perror("недостаточно памяти");
        exit(EXIT_FAILURE);
    }
}

void fill_array_random(int* array, const size_t n, const int min, const int max)
{
    check_array(array);
    if (min > max)
    {
        errno = EINVAL;
        perror("минимум не может быть больше максимума");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; i++)
    {
        array[i] = (rand() % (max - min + 1)) + min;
    }
}

void fill_array_manual(int* array, const size_t n)
{
    check_array(array);
    for (size_t i = 0; i < n; i++)
    {
        printf("введите элемент %zu: ", i);
        array[i] = input();
    }
}

int* copy(const int* array, const size_t n)
{
    check_array(array);
    int* coparray = get_array(n);
    for (size_t i = 0; i < n; ++i)
    {
        coparray[i] = array[i];
    }

    return coparray;
}

void print_array(const int* array, const size_t n)
{
    check_array(array);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int min_elem_index(const int* array, int n)
{
    size_t min_ind = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] < array[min_ind])
        {
            min_ind = i;
        }
    }
    return min_ind;
}

int average_meaning(const int* array, int n)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += array[i];
    }
    double average = sum / n;
    return average;
}

void replace_min_and_average(int* array, int n)
{
    int min_ind = min_elem_index(array, n);
    double average = average_meaning(array, n);
    array[min_ind] = (int)average; // Приводим среднее к целому типу
}

int contains_five(int number)
{
    number = abs(number);
    while (number > 0) {
        if (number % 10 == 5)
        {
            return 1; // Цифра 5 найдена
        }
        number /= 10;
    }
    return 0; // Цифра 5 не найдена
}

int* array_no_five(const int* array, int n, int* m)
{
    int* arr = get_array(n);
    *m = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (contains_five(array[i]) == 0)
        {
            arr[*m] = array[i];
            *m = *m + 1;
        }
    }
    return arr;
}

int* array_a_c(const int* array, int n)
{
    int* arra = get_array(n);
    for (size_t i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arra[i] = pow(array[i], 2);
        }
        else
        {
            arra[i] = array[i] * 2;
        }
    }
    return arra;
}

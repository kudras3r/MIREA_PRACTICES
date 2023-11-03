/* Вариант 2 практическая работа 3 */

#define _USE_MATH_DEFINES 
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <windows.h>

double part1(double x, double y) {
    /* вычисление значения выражения в числителе */
    return pow(8 + pow((abs(x - y)), 2) + 1, ((double)1 / 3));
}
double part2(double x, double y) {
    /* вычисление значения выражения в знаменателе */
    return pow(x, 2) + pow(y, 2) + 2;
}
double part3(double x, double y, double z) {
    /* вычисление значения выражения стоящего в правой части после знака минус */
    return (pow(exp(1), abs(x - y))) * pow((pow(tan(z), 2) + 1), x);
}

double func_is_limited(double x, double y, double z) {
    /* проверка области допустимых значений */
    bool is_limited = true;
    if ((pow(x, 2) + pow(y, 2) + 2) == 0 ||
        z == M_PI / 2) {
        is_limited = false;
    }
    return is_limited;
}

double calculate(double x, double y, double z) {
    /* вычисление заданого выражения */
    double result = 0;
    double numerator = 0;
    double denominator = 0;
    double right_product = 0;

    numerator = part1(x, y);
    denominator = part2(x, y);
    right_product = part3(x, y, z);

    result = (numerator / denominator) - right_product;

    return result;
}
void case1() {
    /* ввод + проверка одз + вывод */
    double x = -4.5;
    double y = 0.75 * pow(10, -4);
    double z = 0.845 * pow(10, 2);
    double u = 0;
    printf("Введите x, y, z >>> ");
    scanf_s("%lf %lf %lf", &x, &y, &z);
    if (func_is_limited(x, y, z)) {
        u = calculate(x, y, z);
        printf("Результат >>> %lf", u);
    }
    else {
        printf("Функция не определена!");
    }
}
void case2() {
    /* ввод + вывод */
    double x = -4.5;
    double y = 0.75 * pow(10, -4);
    double z = 0.845 * pow(10, 2);
    double u = 0;
    printf("Введите x, y, z >>> ");
    scanf_s("%lf %lf %lf", &x, &y, &z);
    u = calculate(x, y, z);
    printf("Результат >>> %lf", u);
}
int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    int user_case = 0;
    printf("(11, 22, 13) - ручной ввод с проверкой области допустимых значений\n");
    printf("(0) - решение без проверки области допустимых значений\n");
    printf("(32) - завершение программы\n");
    printf("(остальные числа) - ошибка\n >>> ");
    scanf_s("%d", &user_case);
    switch (user_case) {
    case 11:
        case1();
        break;
    case 22:
        case1();
        break;
    case 13:
        case1();
        break;
    case 0:
        case2();
        break;
    case 32:
        return 0;
        break;
    default:
        printf(">> ERROR <<");
        break;
    }

    return 0;
}
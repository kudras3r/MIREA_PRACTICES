/* Вариант 2 практическая работа 2 */

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

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    double x = 0;
    double y = 0;
    double z = 0;
    double u = 0;
    printf("Введите x, y, z >>> ");
    scanf_s("%lf %lf %lf", &x, &y, &z);
    u = calculate(x, y, z);
    printf("Результат >>> %lf", u);
    return 0;
}
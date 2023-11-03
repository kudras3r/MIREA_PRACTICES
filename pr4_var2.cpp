#include <iostream>
#include <stdio.h>
#include <windows.h>

bool DotInRangeOfAcceptedValues (double x, double y) {
    if ((x >= -1.5 && x <= 2) && (y >= -1 && y <= 1)) {
        return true;
    }
    else {
        return false;
    }
}

void DotInFirstQuarter (double x, double y) {
    if (y >= -0.5 * x + 1) {
        printf("Dot in area!");
    } 
    else {
        printf("Dot not in area!");
    }
}

void DotInSecondQuarter (double x, double y) {
    if ((y >= (-(double) 2 / 3) * x)) {
        printf("Dot in area!");
    } 
    else {
        printf("Dot not in area!");
    }
}

void DotInThirdQuarter (double x, double y) {
    if ((y <= ((double) 2 / 3) * x) && x <= 0) {
        printf("Dot in area!");
    } 
    else {
        printf("Dot not in area!");
    }
}

void DotInFourthQuarter (double x, double y) {
    if ((y <= 0.5 * x - 1) && x <= 0) {
        printf("Dot in area!");
    } 
    else {
        printf("Dot not in area!");
    }
}

int Quarter (double x, double y) {
    int quarter = 0;
    if (x >= 0 && y >= 0) {
        quarter = 1;
    }
    else if (x <= 0 && y >= 0) {
        quarter = 2;
    }
    else if (x <= 0 && y <= 0) {
        quarter = 3;
    }
    else if (x >= 0 && y <= 0) {
        quarter = 4;
    }
    return quarter;
}

int main () {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    // Dot coords
    double x = 0;
    double y = 0;
    // Input
    printf("Enter the coords of (x, y) dot >>> ");
    scanf_s("%d%d", &x, &y);
    const int QUARTER = Quarter(x, y);
    if (DotInRangeOfAcceptedValues(x, y)) {
        switch (QUARTER) {
            case 1:
                DotInFirstQuarter(x, y);
                break;
            case 2:
                DotInSecondQuarter(x, y);
                break;
            case 3:
                DotInThirdQuarter(x, y);
                break;
            case 4:
                DotInFourthQuarter(x, y);
                break;
        }
    }
    return 0;
}
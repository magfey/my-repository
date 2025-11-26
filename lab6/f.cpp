#include "f.hpp"
#include <iostream>
#include <cmath>

bool isPrime(int x) {
    x = abs(x);
    if (x <= 1) {
        return false;
    }
    for (int d = 2; d <= sqrt(x); ++d) {                    // Функция определение простоты числа
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}

bool isPrimeInM(int** matrix, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (isPrime(matrix[i][j])) {
                return true;
            }
        }
    }
    return false;
}

bool isDStr(int **matrix, int a, int b1, int b2) {
    for (int i = 0; i < a; i++) {
        if (matrix[i][b1] != matrix[i][b2]) {
            return false;
        }
    } 
    return true;
}

bool isDup(int** matrix, int a, int b) {
    for (int i = 0; i < b - 1; i++) {
        for (int j = i + 1; j < b; j++) {
            if (isDStr(matrix, a, i, j)) {
                return true;
            }
        }
    }
    return false;
}

int SwitchStr(int** matrix, int b1, int b2) {
    int* t = matrix[b1];
    matrix[b1] = matrix[b2];
    matrix[b2] = t;
    return 0;
}

int SmStr(int* s, int b) {
    int sm = 0;
    for (int i = 0; i < b; i++) {
        sm += s[i];
    }
    return sm;
}

int SortMatrix(int** matrix, int a, int b) {
    for (int i = 0; i < a - 1; i++) {
        for (int i2 = i + 1; i2 < a;i2++) {
            if (SmStr(matrix[i2], b) < SmStr(matrix[i], b)) {
                SwitchStr(matrix, i, i2);
            }
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
/*
int main() {
    setlocale(LC_ALL, "RU");

    int size;
    bool flag = false;
    std::cout << "Введите размер списка: ";
    std::cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Введите число массива: ";
        std::cin >> arr[i];
        int d = arr[i];
        while (d > 9) {
            d /= 10;
        }
        if (d == 1) {
            flag = true;
        }
    }
    std::cout << "массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    if (flag) {
        std::sort(arr, arr + size);
    }
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
*/
/**/
/*
int FirtstDigit(int num) {
    while (num > 9) {
        num /= 10;
    }
    return num;
}

int SumDigits(int num) {
    int s = 0;
    while (num > 0) {
        s += num % 10;
        num /= 10;
    }
    return s;
}

bool SortFD(int a, int b) {
    if (FirtstDigit(a) != FirtstDigit(b)) {
        return FirtstDigit(a) < FirtstDigit(b);
    }
    if (SumDigits(a) != SumDigits(b)) {
        return SumDigits(a) < SumDigits(b);
    }
    return a < b;


}

int main() {
    setlocale(LC_ALL, "RU");

    int size;
    bool flag = false;
    std::cout << "Введите размер списка: ";
    std::cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Введите число массива: ";
        std::cin >> arr[i];
    }
    std::cout << "массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::sort(arr, arr + size, SortFD);

    std::cout << "массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
*/
/**/

int main() {
    setlocale(LC_ALL, "RU");
    int nstr = 0;
    int sstr = 2147483647;
    int a;
    int b;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    int** arra = new int*[a];
    for (int i = 0; i < a; i++) {
        arra[i] = new int[b];
    }
    for (int i = 0; i < a; i++) {
        int sm = 0;
        for (int j = 0; j < b; j++) {
            std::cout << "Введите число матрицы строки " << i << " столбца " << j << " : ";
            std::cin >> arra[i][j];
            sm += arra[i][j];
        }
        if (sm < sstr) {
            sstr = sm;
            nstr = i;
        }
    }
    std::cout << "матрица: " << std::endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            std::cout << arra[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < b; i++) {
        arra[nstr][i] = 0;
    }
    std::cout << "матрица: " << std::endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            std::cout << arra[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}


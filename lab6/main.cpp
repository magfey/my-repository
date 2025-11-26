#include <iostream>
#include "f.hpp"


int main() {
	setlocale(LC_ALL, "RU");
	/*
	int a;
    int b;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
	*/
	
	int a = 2;
	int b = 3;
	int	**matrix = new int *[a];
	for (int i = 0; i < a; i++) {
		matrix[i] = new int[b];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			std::cout << "Введите число матрицы строки " << i << " столбца " << j << " : ";
			std::cin >> matrix[i][j];

		}
	}
	std::cout << "матрица: " << std::endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	if (isPrimeInM(matrix, a, b)) {
		SortMatrix(matrix, a, b);
	}


	

	std::cout << "матрица: " << std::endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	

	return 0;
}


#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");
	short x; // переменная с числом
    char enter; // переменная с ответами пользователя
	bool x0, x1, x2, x3, x4, x5, x6, x7; // переменные с битами числа
	std::cout << "enter number from 0 to 255: "; // просим число
	std::cin >> x;
	x7 = ((x >> 0) & 1);
	x6 = ((x >> 1) & 1);
	x5 = ((x >> 2) & 1);
	x4 = ((x >> 3) & 1);
	x3 = ((x >> 4) & 1);
	x2 = ((x >> 5) & 1);
	x1 = ((x >> 6) & 1);
	x0 = ((x >> 7) & 1);
	std::cout << "0b" << x0 << x1 << x2 << x3 << x4 << x5 << x6 << x7 << std::endl; // выводим число
    std::cout << "Main power supply status: "; // выводим информацию
    if (((x >> 0) & 1) == 1) {
        std::cout << "Available";
    }
    else {
        std::cout << "Not available";
    }

    std::cout << "\nControl cabinet door status: ";
    if (((x >> 2) & 1) == 1) {
        std::cout << "Open";
    }
    else {
        std::cout << "Closed";
    }

    std::cout << "\nOutput #1 status: ";
    if (((x >> 3) & 1) == 1) {
        std::cout << "Enabled";
    }
    else {
        std::cout << "Disabled";
    }

    std::cout << "\nOutput #2 status: ";
    if (((x >> 4) & 1) == 1) {
        std::cout << "Enabled";
    }
    else {
        std::cout << "Disabled";
    }

    std::cout << "\nBackup battery status: ";
    if (((x >> 5) & 1) == 1) {
        std::cout << "Discharged";
    }
    else {
        std::cout << "Charged";
    }

    std::cout << "\nLast error code: ";
    if (((x >> 6) & 1) == 0 && ((x >> 7) & 1) == 0) {
        std::cout << "00 - No error";
    }
    else if (((x >> 6) & 1) == 1 && ((x >> 7) & 1) == 0) {
        std::cout << "10 - High input voltage";
    }
    else if (((x >> 6) & 1) == 0 && ((x >> 7) & 1) == 1) {
        std::cout << "01 - Low input voltage";
    }
    else {
        std::cout << "11 - Reserved";
    }

    std::cout << std::endl; 
   
    if (((x >> 0) & 1) == 1) { // спрашиваем пользоваетеля стоит ли изменять бит
        std::cout << "Turn off the main power? (y/n):";
        std::cin >> enter;
        if (enter == 'y') {
            x ^= (1 << 0);
        }
    }
    else {
        std::cout << "Turn on the main power? (y/n): ";
        std::cin >> enter;
        if (enter == 'y') {
            x ^= (1 << 0);
        }
    }

    std::cout << std::endl;

    if (((x >> 2) & 1) == 1) {
        std::cout << "Close control cabinet? (y/n): ";
        std::cin >> enter;
        if (enter == 'y') {
            x ^= (1 << 2);
        }
    }
    else {
        std::cout << "Open the control cabinet? (y/n): ";
        std::cin >> enter;
        if (enter == 'y') {
            x ^= (1 << 2);
        }
    }

    std::cout << std::endl;

    if (((x >> 3) & 1) == 1) {
        std::cout << "Turn off output 1? (y/n):";
        std::cin >> enter;
        if (enter == 'y') {
            x ^= (1 << 3);
        }
    }
    else {
        std::cout << "Turn on output 1? (y/n): ";
        std::cin >> enter;
        if (enter == 'y') {
            x ^= (1 << 3);
        }
    }

    std::cout << std::endl;

    if (((x >> 4) & 1) == 1) {
        std::cout << "Turn off output 2? (y/n): ";
        std::cin >> enter;
        if (enter == 'y') {
            x ^= (1 << 4);
        }
    }

    else {
        std::cout << "Turn on output 2? (y/n): ";
        std::cin >> enter;
        if (enter == 'y') {
            x ^= (1 << 4);
        }
    }
    
    x7 = ((x >> 0) & 1); // выводим новое двоичное число
    x6 = ((x >> 1) & 1);
    x5 = ((x >> 2) & 1);
    x4 = ((x >> 3) & 1);
    x3 = ((x >> 4) & 1);
    x2 = ((x >> 5) & 1);
    x1 = ((x >> 6) & 1);
    x0 = ((x >> 7) & 1);
    std::cout << "0b" << x0 << x1 << x2 << x3 << x4 << x5 << x6 << x7 << std::endl;
    std::cout << x;

    return 0;
}
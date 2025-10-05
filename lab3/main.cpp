#include <iostream>
#include <numbers>


//Лекция 3

int main() {
    /*
    const double PI = acos(-1); // арккосинус -1 = PI 
    double r;
    std::cin >> r;
    double S =PI * pow(r, 2);
    std::cout << S << std::endl; 
    
    std::cout << INT_MAX << std::endl;
    std::cout << std::numeric_limits<int>::max() << std::endl;
    */

    /* Битовый сдвиг
    int x = 2;
    int y = (x << 1); // Битовый сдвиг << - влево >> - вправо
    std::cout << y << std::endl;
    // Битовый &
    int a = 0b0010;
    int b = 0b1110;
    // 0b0010
    std::cout << (a & b) << std::endl;
    int c = 11;
    // 0b1011                     Проверка четности числа
    // 0b0001
    std::cout << (c & 1) << std::endl;
    */

    /* Битовое | (дизъюнкция)
    int a = 0b0010;
    int b = 0b1110;
    // 0b1110
    
    // Битовая инверсия (~)
    int d = 0b1010;
    std::cout << ~d << std::endl; // 0b0101

    // Битовый xor (^) (Исключающее или: если числа одинаковые, то 0, если разные, то 1)
    int a = 0b1010;
    int b = 0b1110;
    // 0b0101

    // Сдвиг на i-ый бит
    int i = 5;
    char lamp_status = 0b0000'0000;
    std::cout << (lamp_status | (1 << i)) << std::endl; // сдвиг на i-ый бит
    

    int x = 11;
    bool isEven = x % 2;
    std::cout << isEven << std::endl;
    */

    // Логические операторы
    // ==, !=, !, <, > , <=, >=
    // && это логическое И
    // || это логическое ИЛИ
    // ! это логическое НЕ
    /*
    int x = 10;
    bool f = ((x == 10) || (x++)); // short-curcuit evaluation (краткосрочная оценка)
    std::cout << x << std::endl;*/
    // 10

    /* Условный оператор if else
    int x = 11;
    bool isEven = (x % 2 == 0);
    if (isEven) {
        if (x == 13) {
            std::cout << "Even" << std::endl;
        }
        else {
            //...
        }
    }
    else if (x == 12) {
        std::cout << "abcd" << std::endl;
    }    
    else {
        std::cout << "Odd" << std::endl;
    }
    */

    /* Switch
    int monthNumber = 13;
    switch (monthNumber) {
        case 0:std::cout << "January"; break;
        case 1:std::cout << "February"; break;
        // ...
        default:std::cout << "Unknowen number"; break; // Если не попал не в один из кейсов
    }

    // Тернарый (компактный, но плохая читаемость)
    int x = 11;
    std::cout << (x % 2 == 0 ? "Even" : "Odd");
    */
return 0;
}




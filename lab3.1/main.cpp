#include <iostream>
#include <string>
#include "inc/my_lib.hpp"


int main() {
    int e;
    Student student("Egor", "Alexandrov", "Sergeevich", "IP", 1, 2, 12345);
    do {
        std::cout << "1 - toString(), 2 - nextCourse(), 3 - getCourse(), 0 - exit: ";
        std::cin >> e;
        switch (e){
        case 0:
        break;
        case 1:
        std::cout << student.toString();
        break;
        case 2:
        std::cout << "course: " << student.getCourse() << "-->";
        student.nextCourse();
        std::cout << student.getCourse() << std::endl;
        break;
        case 3:    
        std::cout << "course: " << student.getCourse() << std::endl;
        break;
        default:
        std::cout << "invalid value" << std::endl;
        break;
        }
    } while (e != 0);
    return 0;
}

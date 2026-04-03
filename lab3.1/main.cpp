#include <iostream>
#include <string>
#include "inc/my_lib.hpp"


int main() {
    int e;
    Student student("Egor", "Alexandrov", "Sergeevich", "IP", 1, 2, 12345);
    do {
        std::cout << "Choose what you want to do" << std::endl;
        std::cout << "1. Display full information" << std::endl;
        std::cout << "2. Move to the next course" << std::endl;
        std::cout << "3. Get ccourse number" << std::endl;
        std::cout << "0. Exit the proram" << std::endl;
        std::cout << ": ";
        std::cin >> e;
        switch (e){
        case 0:
        break;
        case 1:
        std::cout << student.toString();
        break;
        case 2:
        if (student.getCourse() >= 5) {
            std::cout << "Cours is max" << std::endl;
        }
        else {
            std::cout << student.getCourse() << " --> ";
            student.nextCourse();
            std::cout << student.getCourse() << std::endl;
        }
        std::cout << "course: " << student.getCourse() << "-->";
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

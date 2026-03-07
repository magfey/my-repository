#include <iostream>
#include "inc/my_lib.hpp"


int main() {
    try {
        Student student("Egor", "Alexandrov", "IP", 1, 2, 12345);
        std::cout << student.toString() << std::endl;
        std::cout << "course: " << student.getCourse() << std::endl;
        student.nextCourse();
        std::cout << "course: " << student.getCourse() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}

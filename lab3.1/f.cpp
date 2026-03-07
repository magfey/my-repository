#include "f.hpp"
#include <iostream>
#include <sstream>

// Конструктор по умолчанию
Student::Student() 
    : surname(""), name(""), patronymic(""), 
      course(1), group(0), recordBookNumber("") {
    std::cout << "Вызван конструктор по умолчанию" << std::endl;
}

// Конструктор с параметрами
Student::Student(const std::string& surname, const std::string& name, 
                 const std::string& patronymic, int course, int group, 
                 const std::string& recordBookNumber)
    : surname(surname), name(name), patronymic(patronymic),
      course(course), group(group), recordBookNumber(recordBookNumber) {
    std::cout << "Вызван конструктор с параметрами" << std::endl;
}

// Конструктор копирования (глубокое копирование)
Student::Student(const Student& other)
    : surname(other.surname), name(other.name), patronymic(other.patronymic),
      course(other.course), group(other.group), recordBookNumber(other.recordBookNumber) {
    std::cout << "Вызван конструктор копирования" << std::endl;
}

// Деструктор
Student::~Student() {
    std::cout << "Вызван деструктор для студента: " 
              << surname << " " << name << std::endl;
}

// Метод toString - возвращает строковое представление объекта
std::string Student::toString() const {
    std::stringstream ss;
    
    // Формируем инициалы: И.И.
    std::string initials;
    if (!name.empty() && !patronymic.empty()) {
        initials = name.substr(0, 1) + "." + patronymic.substr(0, 1) + ".";
    } else {
        initials = "";
    }
    
    ss << surname << " " << initials 
       << ", курс " << course 
       << ", группа " << group 
       << ", зач. № " << recordBookNumber;
    
    return ss.str();
}

// Метод для перевода на следующий курс
void Student::nextCourse() {
    if (course < 5) {
        course++;
        std::cout << "Студент переведен на " << course << " курс" << std::endl;
    } else {
        std::cout << "Студент уже на 5 курсе (выпускной курс)" << std::endl;
    }
}

// Метод для получения текущего курса
int Student::getCourse() const {
    return course;
}
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string surname;      // фамилия
    std::string name;         // имя
    std::string patronymic;   // отчество
    int course;               // номер курса
    int group;                // номер группы
    std::string recordBookNumber; // номер зачётной книжки

public:
    // Конструкторы
    Student();
    Student(const std::string& surname, const std::string& name, 
            const std::string& patronymic, int course, int group, 
            const std::string& recordBookNumber);
    Student(const Student& other);
    
    // Деструктор
    ~Student();
    
    // Методы
    std::string toString() const;
    void nextCourse();
    int getCourse() const;
};

#endif // STUDENT_H
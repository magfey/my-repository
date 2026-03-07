#include <iostream>
#include <string>


class Student {
public:
    Student();
    ~Student();
    Student(const std::string& name, const std::string& surname, const std::string& academic_program, int course, int group, int variant);
    Student(const Student& other);
    int getCourse() const;
    void nextCourse();
    std::string toString();
private:
    std::string name_;
    std::string surname_;
    std::string academic_program_;
    int course_;
    int group_;
    int variant_;
};
#include "../inc/my_lib.hpp"
#include <iostream>
#include <string>

using namespace std;



  Student::Student() {
    name_ = "-";
    surname_ = "-";
    academic_program_ = "-";
    course_ = 0;
    group_ = 0;
    variant_ = 0;
    cerr << "ctor" << endl;
  }
  Student::~Student() {
    cerr << "dtor" << endl;
  }
  Student::Student(const string& name, const string& surname, const string& academic_program, int course, int group, int variant) {
    name_ = name;
    surname_ = surname;
    academic_program_ = academic_program;
    course_ = course;
    group_ = group;
    variant_ = variant;
    cerr << "ctor param" << endl;
  }

  
  int Student::getCourse() const { return course_; }

  void Student::nextCourse() {
    if (course_ < 5) {
        course_ += 1;
    }
  }


  string Student::toString() {
    string result = surname_ + " " + name_.substr(0, 1) + "., ";
    result += "course " + to_string(course_) + ", ";
    result += "group " + to_string(group_) + ", ";
    result += "zach. № " + to_string(variant_);
    return result;
  }


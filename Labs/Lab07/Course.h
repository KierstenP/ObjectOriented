#ifndef COURSES_H
#define COURSES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace BrooklynPoly {

    class Student;

    class Course {
    public:
        Course(const std::string& theName);
        void addStudent(Student& aStudent);
        size_t findIndexStudent(const std::string& studentName);
        void removeStudent(const std::string& theName);
        void clearStudents();
        std::string getName();
    private:
        std::string name;
        std::vector<Student*> students;
    };

}

#endif
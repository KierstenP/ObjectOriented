#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace BrooklynPoly {

    class Course;

    class Student {
        friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
    public:
        Student(const std::string& theName);
        void addCourse(Course& aCourse);
        std::string getName();
        size_t findIndexCourses(const std::string& courseName);
        void removeCourse(const std::string& courseName);
    private:
        std::string name;
        std::vector <Course*> courses;
    };

}

#endif
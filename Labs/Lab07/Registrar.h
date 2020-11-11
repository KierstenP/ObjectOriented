
#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <ostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace BrooklynPoly {
    class Student;
    class Course;

    class Registrar {
        friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
    public:
        Registrar();
        /*
        FIND METHODS
        */
        size_t findStudentIndex(const std::string& studentName);

        size_t findCourseIndex(const std::string& courseName);
        /*
        ADD COURSES
        */
        void addCourse(const std::string& courseName);

        void addStudent(const std::string& studentName);

        //ENROLL STUDENT
        void enrollStudentInCourse(const std::string& nameStudent, const std::string& nameCourse);

        void cancelCourse(const std::string& nameCourse);

        void purge();
    private:
        std::vector<Student*> students;
        std::vector<Course*> courses;
    };
}

#endif
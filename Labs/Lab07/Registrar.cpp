#include "Registrar.h"
#include "Student.h"
#include "Course.h"

namespace BrooklynPoly {
    std::ostream & operator<<(std::ostream & os, const Registrar & rhs)
    {
        os << "Registrar's Report" << std::endl;
        os << "Courses: " << std::endl;
        for (size_t i = 0; i < rhs.courses.size(); ++i) {
            os << rhs.courses[i]->getName() << ", " ;
        }
        os << std::endl;
        os <<"Students:" << std::endl;
        for (size_t j = 0; j < rhs.students.size(); ++j) {
            os << *(rhs.students[j]);
        }
        return os;
    }

    Registrar::Registrar() {}
    /*
    FIND METHODS
    */
    size_t Registrar::findStudentIndex(const std::string& studentName) {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i]->getName() == studentName) {
                return i;
            }
        }
        return students.size();
    }

    size_t Registrar::findCourseIndex(const std::string& courseName) {
        for (size_t i = 0; i < courses.size(); ++i) {
            if (courses[i]->getName() == courseName) {
                return i;
            }
        }
        return courses.size();
    }
    /*
    ADD COURSES
    */
    void Registrar::addCourse(const std::string& courseName) {
        Course* tempCourse = new Course(courseName);
        courses.push_back(tempCourse);
    }

    void Registrar::addStudent(const std::string& studentName) {
        Student* tempStudent = new Student(studentName);
        students.push_back(tempStudent);
    }

    //ENROLL STUDENT
    void Registrar::enrollStudentInCourse(const std::string& nameStudent, const std::string& nameCourse) {
        size_t indexOfStudent = findStudentIndex(nameStudent);
        size_t indexOfCourse = findCourseIndex(nameCourse);

        if (indexOfStudent != students.size() && indexOfCourse != courses.size()) {
            courses[indexOfCourse]->addStudent(*students[indexOfStudent]);
            students[indexOfStudent]->addCourse(*courses[indexOfCourse]);
        }

        if (indexOfCourse == courses.size() || indexOfStudent == students.size()) {
            std::cout << "Student or course is not found" << std::endl;
        }
    }


    void Registrar::cancelCourse(const std::string& nameCourse) {
        size_t indexOfCourse = findCourseIndex(nameCourse);
        if (indexOfCourse != courses.size()) {
            courses[indexOfCourse]->clearStudents();//Clears the students from the course
            delete courses[indexOfCourse];
            for (size_t i = indexOfCourse; i < courses.size() - 1; ++i) {
                courses[indexOfCourse] = courses[indexOfCourse + 1];
            }
            courses.pop_back();
        }
    }

    void Registrar::purge() {
        for (size_t i = 0; i < students.size(); ++i) {
            delete students[i];
        }

        for (size_t i = 0; i < courses.size(); ++i) {
            delete courses[i];
        }
        courses.clear();
        students.clear();
    }
}
#include "Student.h"
#include "Course.h"

namespace BrooklynPoly {
    Course::Course(const std::string& theName) : name(theName) {}
    void Course::addStudent(Student& aStudent) {
        students.push_back(&aStudent);
    }
    size_t Course::findIndexStudent(const std::string& studentName) {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i]->getName() == studentName) {
                return i;
            }
        }
        return students.size();
    }

    void Course::removeStudent(const std::string& theName) {
        size_t index = findIndexStudent(theName);
        if (index != students.size()) {
            delete students[index];
            for (size_t i = index; i < students.size() - 1; ++i) {
                students[i] = students[i + 1];
            }
            students.pop_back();
        }
        else {
            std::cout << "Student to remove not found" << std::endl;
        }
    }
    void Course::clearStudents() {
        for (size_t i = 0; i < students.size(); i++) {
            students[i]->removeCourse(name);
            //Don't want to delete, b/c I want the students still in the heap, and existing
            //even if a course gets deleted. I just want the students to forget about this course.
        }
    }
    std::string Course::getName() {
        return name;
    }
}
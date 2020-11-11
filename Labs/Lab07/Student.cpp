#include "Student.h"
#include "Course.h"
namespace BrooklynPoly {
    std::ostream& operator<<(std::ostream& os, const Student& rhs) {
        os << rhs.name << ":" << std::endl;
        for (size_t i = 0; i < rhs.courses.size(); ++i) {
            os << "\t" << rhs.courses[i]->getName() << std::endl;
        }
        return os;
    }

    Student::Student(const std::string& theName) : name(theName) {}
    void Student::addCourse(Course& aCourse) {
        courses.push_back(&aCourse);
    }

    size_t Student::findIndexCourses(const std::string& courseName) {
        for (size_t i = 0; i < courses.size(); ++i) {
            if (courses[i]->getName() == courseName) {
                return i;
            }
        }
        return courses.size();
    }
    void Student::removeCourse(const std::string& courseName) {
        size_t index = findIndexCourses(courseName);
        if (index != courses.size()) {
            for (size_t i = index; i < courses.size() - 1; ++i) {
                courses[i] = courses[i + 1];
            }
            courses.pop_back();
        }
        else {
            std::cout << "Course to remove not found" << std::endl;
        }

    }
    std::string Student::getName() {
        return name;
    }
}
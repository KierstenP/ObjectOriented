/* Author: Kiersten Page
 * Purpose: Model the CS Lab administration
 * rec05
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LabWorker;
class Section;


class Section{
public:
    friend ostream& operator <<(ostream& os, const LabWorker& labWorker);
    friend ostream& operator <<(ostream& os, const Section& section);
    Section(const string& name,  const string& day, const int& hour) : name(name), timeSlot(day, hour){} //initial constructor
    ~Section() {    //destructor
        cout << "Section " << name << "is being deleted. " << endl;
        for (size_t i = 0; i < students.size() ; ++i) {
            cout << "Deleting " << students[i]->returnName()<< endl;
            delete students[i];
        }
        students.clear();
    }
    Section(const Section& rhs) : timeSlot(rhs.timeSlot){   //copy constructor
        for (StudentRecord* s : rhs.students) {
            students.push_back(new StudentRecord(*s));
        }
    }
    void addStudent(const string& name){
        StudentRecord* student = new StudentRecord(name);
        students.push_back(student);
    }
    void addGrade(const string& name,  int& gradeOne,  int& week){
        for(size_t i = 0; i < students.size() ; ++i){
            if(students[i]->returnName() == name){
                students[i]->addGrades(gradeOne, week);
            }
        }
    }

private:
    class TimeSlot {
    public:
        friend ostream& operator <<(ostream& os, const Section& section);
        TimeSlot(const string& day, int hour) : day(day), hour(hour) {}
        void display() const {  //displays a section's day and hour
            cout << "Time slot: [Day: " << day << ", Start Time: ";
            if(hour < 12){
                cout << hour << "am]";
            }
            else if(hour == 12){
                cout << hour << "pm]";
            }
            else{
                cout << (hour - 12) << "pm]";
            }
        };
    private:
        string day;
        int hour;
    };
    class StudentRecord{
    public:
        StudentRecord(const string& name) : name(name), grades(14, -1){};
        void addGrades(int& gradeOne, int& week){
            grades[week - 1] = gradeOne;
        }
        string returnName(){
            return name;
        }
        void display() const {  //displays a students name and grades
            cout << "Name: " << name << "Grades: ";
            for (size_t i = 0 ; grades.size() ; ++i){
                cout<< grades[i] << " ";
            }
            cout << endl;
        }
    private:
        string name;
        vector<int> grades;
    };
    string name;
    TimeSlot timeSlot;
    vector<StudentRecord*> students;
};

class LabWorker{
public:
    LabWorker(const string& name) : name(name), section(nullptr){};
    friend ostream& operator <<(ostream& os, const LabWorker& labWorker);
    void addSection(Section& section1){
        section = &section1;
    }
    void addGrade(const string& name, int& gradeOne, int& week){
        section->addGrade(name, gradeOne, week);
    }
private:
    string name;    //lab worker's name(will be initialized with it)
    Section* section;   //lab workers will only have one lab (initialized to nullptr upon creation)

};

ostream& operator <<(ostream& os, const LabWorker& labWorker){
    if(labWorker.section == nullptr){


    }
    else{
        os << labWorker.name << "has ";
        os << labWorker.section;
        return os;
    }

}
ostream& operator <<(ostream& os, const Section& section){
    os << "Section: " << section.name ;
    section.timeSlot.display();
    os << endl;
    for(size_t i = 0; i < section.students.size() ; ++i){
        section.students[i]->display();
    }
    return os;
}
// Test code
void doNothing(Section sec) {
    cout << sec << endl;;
}

int main() {

    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe("Moe");
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection(secA2);
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection(secB3);
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works properly, i.e. no memory leaks\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main
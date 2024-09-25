#include "Student.h"

Student::Student (std::string fName, std::string lName, int id) : firstName(fName), lastName(lName), id(id), gradeCount(0) {

    for (int i = 0; i < 10; i++) {
        grade[i] = 0;
    }
}
void Student::setFirsttName(std::string fName) {
    this->firstName = fName;
}
std::string Student::getFirstName() const {
   return 0;
}

void Student::setLasttName(std::string fName) {
     this->lastName = lName;
}
std::string Student::getLastName() const {
    return 0;
}

void Student::setId(int id) {
    this->id = id;
}
int getId() const {
    return 0;
}

void Student::addGrade(int grade) {
    std::cout
}
int* getGrades();
int getGradeCount() const;

 double calculateAverage() const;

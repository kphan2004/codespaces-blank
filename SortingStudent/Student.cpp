#include "Student.h"

Student::Student(string firstName, string lastName, int idNum)
        : firstName(firstName), lastName(lastName), ID(idNum) {
}

string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}
int Student::getID() {
    return ID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setID(int idNum) {
    this->ID = idNum;
}

bool Student::operator<(Student& other) {
    return this->ID < other.ID;
}
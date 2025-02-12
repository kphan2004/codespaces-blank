#include "Student.h"

Student::Student() : firstName(""), lastName(""), id(0) {
    
}

Student::Student(string firstName, string lastName, int id)
    : firstName(firstName), lastName(lastName), id(id) {
}

string Student::getFirstName() const {
    return firstName;
}
string Student::getLastName() const {
    return lastName;

}
int Student::getId() const {
    return id;
}
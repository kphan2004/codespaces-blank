// Student.cpp
#include "Student.h"

// Constructor - initializes student object with given first name, last name, and ID
Student::Student(string firstName, string lastName, int idNum)
        : firstName(firstName), lastName(lastName), ID(idNum) {
}

// Getters
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}
int Student::getID() {
    return ID;
}

// Setters
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setID(int idNum) {
    this->ID = idNum;
}

// Overloaded < operator to compare students by ID
bool Student::operator<(Student& other) {
    return this->ID < other.ID;     // Return to id less than other students ID
}
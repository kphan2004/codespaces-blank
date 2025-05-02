// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

// Defines the Student class to hold student information and comparison logic
class Student {
    private:
        // Private data members: first name, last name, and student ID
        string firstName;
        string lastName;
        int ID;

    public:
        // Constructor with default values
        Student (string firstName = " ", string lastName = " ", int idNum = 0);

        // Getters
        string getFirstName();
        string getLastName();
        int getID();

        // Setters
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setID(int idNum);

        // Overloaded operator < to compare Students by ID
        bool operator<(Student& other);

};

#endif
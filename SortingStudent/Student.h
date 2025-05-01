#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
    private:
        string firstName;
        string lastName;
        int ID;

    public:
        Student (string firstName = " ", string lastName = " ", int idNum = 0);

        string getFirstName();
        string getLastName();
        int getID();

        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setID(int idNum);

        bool operator<(Student& other);

};

#endif
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {

private:
    string firstName;
    string lastName;
    int id;

public:
    Student();
    Student(string firstName, string lastName, int id);
    string getFirstName() const;
    string getLastName() const;
    int getId() const;


};



#endif //STUDENT_H
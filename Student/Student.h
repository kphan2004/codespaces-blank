#ifndef STUDENT_H
#define STUDENT_H

#include <string> 

class Student {
    private:
        std::string fName;
        std::string lName;
        int id;
        int grades[10]; //array to store grades max[10]
        float gradeCount; //to keep track of the number of grades entered

    public:
        Student();
        Student(std::string fName, std::string lName, int id);

        void setFirsttName(std::string fName);
        std::string getFirstName() const;

        
        void setLasttName(std::string fName);
        std::string getLastName() const;

        void setId(int id);
        int getId() const;

        void addGrade(int grade);
        int* getGrades();
        int getGradeCount() const;

        double calculateAverage() const;

};

#endif
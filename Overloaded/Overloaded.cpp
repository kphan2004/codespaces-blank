#include <iostream>
#include <string>

class Student {
    private: 
        std::string name;
        int studentID;
        std::string address;

    public:
        //Constructor to initialize the Student object
        Student(const std::string name, int studentID, std::string address) :
            name(name), studentID(studentID), address(address) {};

        // Overloaded the << operator for priting 
        friend std::ostream& operator << (std::ostream& os, const Student& student) {
            os << "Name: " << student.name << "\n";
            os << "Student ID: " << student.studentID << "\n";
            os << "Address: " << student.address << "\n";
            return os;
        }
};

int main() {

    // Create a Student object
    Student student ("Kirian Phan" , 11243, "123 Main St, Anytown, USA");

    // Overloaded the << operator for priting Student object
    std::cout << student;

    return 0;
}
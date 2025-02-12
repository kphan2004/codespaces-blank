#include "Student.h"
#include "Comparator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<typename Object, typename Comparator>
const Object & findMax(const vector<Object> & list, const Comparator & cmp) {
    int MAX = 0;
    for (int i = 0; i < list.size(); i++) {
        if (cmp.isLessThan(list[MAX], list[i])) {
            MAX = i;
        }
    }
    return list[MAX];
}

int main() {
    vector<Student> students;
    ifstream file("input.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, lastName, firstName;

        getline(ss, idStr, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');

        int id = stoi(idStr);
        students.push_back(Student(firstName, lastName, id));
    }

    cout << "All Students have been added" << endl;
    for (const Student & s : students) {
        cout << s.getId() << ": " << s.getFirstName() << ", " << s.getLastName() << endl;
    }
    cout << endl;


    StudentIdComparator idCmp;
    Student maxById = findMax(students, idCmp);
    cout << "Student with highest id: \n";
    cout << maxById.getId() << ": " << maxById.getFirstName() << ", " << maxById.getLastName() << endl;
    cout << endl;


    StudentNameComparator nameCmp;
    Student maxByName = findMax(students, nameCmp);
    cout << "Student with ID, First & Last Name Combination: \n";
    cout << maxByName.getId() << ": " << maxByName.getFirstName() << ", " << maxByName.getLastName() << endl;
    cout << endl;

    return 0;
}
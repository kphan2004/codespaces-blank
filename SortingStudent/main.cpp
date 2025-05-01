#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Student.h"

using namespace std;

void insertionSort(Student* students, int size) {
    for (int i = 1; i < size; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && key < students[j]) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Error opening input.txt\n";
        return 1; 
    }

    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int count = 0;
    string line;

    while (getline(file, line) && count < MAX_STUDENTS) {
        stringstream ss(line);
        string idStr, lastName, firstName;
        getline(ss, idStr, ',');
        getline(ss, lastName, ',');
        getline(ss, firstName);

        int id = stoi(idStr);
        students[count].setFirstName(firstName);
        students[count].setLastName(lastName);
        students[count].setID(id);
        count++;
    }
    file.close();

    insertionSort(students, count);

    cout << left << setw(10) << "ID" << setw(15) << "Last Name" << setw(15) << "First Name" << endl;
    cout << "------------------------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << students[i].getID()
             << setw(15) << students[i].getLastName()
             << setw(15) << students[i].getFirstName() << endl;
    }

    return 0;
}
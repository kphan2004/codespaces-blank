// main.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Student.h"

using namespace std;

// Insertion Sort implementation to sort students by ID
void insertionSort(Student* students, int size) {
    for (int i = 1; i < size; i++) {
        Student temp = students[i];  // Current student to insert
        int j = i - 1;
        // Shift students with larger IDs to the right
        while (j >= 0 && temp < students[j]) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = temp; // Insert temp into correct position
    }
}

// main function
int main() {
    ifstream file("input.txt");     // Open input file
    if (!file) {
        cerr << "Error opening input.txt\n";    // The file will be error when open wrong
        return 1; 
    }

    const int MAX_STUDENTS = 100;   // Max limit for safety
    Student students[MAX_STUDENTS];
    int count = 0;
    string line;

    // Read file line by line
    while (getline(file, line) && count < MAX_STUDENTS) {
        stringstream ss(line);
        string idStr, lastName, firstName;
        getline(ss, idStr, ',');
        getline(ss, lastName, ',');
        getline(ss, firstName);

        int id = stoi(idStr);   // Convert ID from string to integer
        // Assign values to student object
        students[count].setFirstName(firstName);
        students[count].setLastName(lastName);
        students[count].setID(id);
        count++;
    }
    file.close();   // Done reading

    // Sort students by ID using insertion sort
    insertionSort(students, count);

    // Print header
    cout << left << setw(10) << "ID" << setw(15) << "Last Name" << setw(15) << "First Name" << endl;
    cout << "------------------------------------" << endl;
    // Print sorted students
    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << students[i].getID()
             << setw(15) << students[i].getLastName()
             << setw(15) << students[i].getFirstName() << endl;
    }

    return 0;
}
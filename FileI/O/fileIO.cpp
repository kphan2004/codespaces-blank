#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Person {
    private:
        string name;
        int age;
        float height;
    public:
        Person(string n = "", int a = 0, float h = 0.0f) : name(n), age(a), height(h) {}
        void display() const {
            cout << "Name: " << name << "\nAge: " << age << "\nHeight: " << height << endl;
        }

}
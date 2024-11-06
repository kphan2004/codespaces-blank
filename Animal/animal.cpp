#include <iostream>
#include <string>
using std::cout;
using std::endl;

class Animal {
    public:
    virtual void speak() const = 0;   
};
class Dog : public Animal {
    public:
        void speak() const {
                cout << "Woof! Woof!" << endl;
        }
};
class Cat : public Animal {
    public:
        void speak() const {
            cout << "Meow! Meow!" << endl;
        }
};
int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    myDog->speak();
    myCat->speak();
    delete myDog;
    delete myCat;

    return 0;
}
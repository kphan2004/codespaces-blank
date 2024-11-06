#include <iostream>
#include <cmath>
#include <ostream>

// Base class
class Shape {
    public: 
        virtual void read(std::istream& in) = 0;
        virtual double area() const = 0;
        virtual void display(std::ostream& out) const = 0;
};

// Derived class for Circle
class Circle : public Shape {
    private:
        double radius;
    
    public:
        void read(std::istream& in) {
            std::cout << "Enter Radius: ";
            in >> radius;
        }
        double area() const {
            return M_PI * radius * radius;
        }
        void display(std::ostream& out) const {
            out << "Circle with radius " << radius;
        }
};

// Derived class for Rectangle
class Rectangle : public Shape {
    private:
        double width, height;

    public:
        void read(std::istream& in) {
            std::cout << "Enter width and height: ";
            in >> width >> height;
        }
        double area() const {
            return width * height;
        }
        void display(std::ostream& out) const {
            out << "Rectangle with width " << width << " and height " << height;
        }
};

class Triangle : public Shape {
    private:
        double base, height;

    public:
        void read(std::istream& in) {
            std::cout << "Enter base and height: ";
            in >> base >> height;
        }
        double area() const {
            return base * height;
        }
        void display(std::ostream& out) const {
            out << "Rectangle with base " << base << " and height " << height;
        }
};

// Function to print shape area
void printArea(Shape* shape) {
    shape->display(std::cout);
    std::cout << " has an area of: " << shape->area() << std::endl;
}

// Main function
int main() {
    Shape* shape = nullptr;
    int choice;

    std::cout << "Choose a shape (1 = Circle, 2 = Rectangle, 3 = Triangle): ";
    std::cin >> choice;

    if (choice == 1) {
        shape = new Circle();
    } else if (choice == 2) {
        shape = new Rectangle();
    } else if (choice == 3) {
        shape = new Triangle();
    } else {
        std::cout << "Invalid choice." << std::endl;
        return 1;
    }
    

    shape->read(std::cin);
    printArea(shape);

    delete shape; // Clean up allocated memory
    return 0;
}
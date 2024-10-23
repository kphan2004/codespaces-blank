#include <iostream>
using namespace std;
//SINGLE INHERITANCE

// base class: Rectangle
class Rectangle {
    protected:
        double width, height;
    
    public:
        // Constructor for Rectangle
        Rectangle(double w, double h) : width(w), height(h){
        }
        //Method to calculate area
        double area() const {
            return width * height;
        }        
        // Method to display dimensions
        void displayDimensions() {
            cout << "Width: " << width << "\nHeight: " << height << endl;
        }
};

// Derived class: Square (inherits from Rectangle)
class Square : public Rectangle {
    public:
        //Constructor for Square
        Square(double side) : Rectangle(side, side) {
        } // Passes side as both width and height to Rectangle
        
        //Method to displat the side of the square
        void displaySide() const {
            cout << "Side: " << width << endl; // Since it's a square, width, and height are the same
        }
};

int main() {
    // Create a rectangle
    Rectangle rect(5.0, 3.0);
    cout << "Rectangle: " << endl;
    rect.displayDimensions();
    cout << "Area: " << rect.area() << endl;

    // Create a square
    Square sq(4.0);
    cout << "\nSquare: " <<  endl;
    sq.displaySide();
    cout << "Area: " << sq.area() << endl;

    return 0;
}
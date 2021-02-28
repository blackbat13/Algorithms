//
// Created by Damian Kurpiewski on 21.11.2017.
//

#include <iostream>

using namespace std;

// ------- SECTION 1 -------

// Basic structure, containing only two elements of type int
// We use word struct to define structure
// After word struct we write name of our structure
// By default we should begin names of structures from upper case
struct Point {
    int x;
    int y;
};


// ------- SECTION 2 -------

// Structure containing three variables of type double and a method
/// Structure representing 3d point
struct Point3D {
    double x;
    double y;
    double z;

    // Custom method (function) assigned to Point3D type
    /// Prints out description of the Point3D
    void describe() {
        cout << "x = " << x << ", ";
        cout << "y = " << y << ", ";
        cout << "z = " << z << endl;
    }
};


// ------- SECTION 3 -------

/// Structure representing the rectangle
struct Rectangle {
    // By default everything in the structure is defined as public
    // That means that it can be accessed from any context in the code

    // But we can override this behaviour
    // We can explicit say, that some fields (or methods) should be defined as private
    // Private fields (or methods) can only be accessed from the inside of the structure

    // Everything defined after the "private" keyword is considered as private
    // Until we reach "public" keyword or the end of the structure
private:
    // Fields width and height can only be accessed in this structure
    double width;
    double height;

    // Everything defined after the "public" keyword is considered as public
    // Until we reach "private" keyword or the end of the structure
public:
    // This methods can be accessed from outside of this structure

    // Because we defined fields as private, we now don't have default constructor
    // That means we cannot create new variable of type Rectangle and assign value to it using {} notation
    // To use this default notation we must define our custom constructor
    // Constructor is a special function that is called when we assign new beginning value to our struct variable
    // This function doesn't have a type and shouldn't return any value
    // It can have as many parameters as we want
    // Constructor should assign some values to the fields of our structure

    /// Constructor setting width and height of the rectangle
    /// \param w - width of the rectangle
    /// \param h - height of the rectangle
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    /// Compute area of the rectangle
    /// \return Area of the rectangle
    double area() {
        // We can use this private fields because we aer still inside the structure
        return width * height;
    }

    /// Scale rectangle by given scale
    /// \param sc - scale by which rectangle should be scaled
    void scale(double sc) {
        width *= sc;
        height *= sc;
    }
};

int main() {
    // ------- SECTION 1 -------

    // After creating structure we can use it as a new type for our variables
    // Now we create variable named "point" of type Point
    Point point;

    // We assign new value to our point variable
    // We assign values to the corresponding fields of the Point structure
    // 5 is assigned to the first field in the structure - x
    // 3 is assigned to the second field in the structure - y
    cout << "Creating new point with x = 5 and y = 3" << endl;
    point = {5, 3};

    // To access field from our variable of type Point we write: variable_name.field_name
    // For example to access field x: point.x
    cout << "Point x: " << point.x << endl;
    cout << "Point y: " << point.y << endl;

    // We can also assign new values to fields this way
    cout << endl << "Assigning new values to the point variable" << endl;
    point.x = 20;
    point.y = 13;
    cout << "Point x: " << point.x << endl;
    cout << "Point y: " << point.y << endl;



    // ------- SECTION 2 -------

    Point3D point3D = {5.7, 2.3, 9.0};

    // Our Point3D structure have one method (function): describe
    // To use it we write: variable_name.method_name
    cout << endl << "Calling method describe for point3D" << endl;
    point3D.describe();



    // ------- SECTION 3 -------

    Rectangle rectangle = {4, 2};

    // We cannot access width of this rectangle, because this field is defined as private
    // cout << "Rectangle width: " << rectangle.width << endl;

    // We can use method are of the rectangle, because it is defined as public
    cout << "Rectangle area: " << rectangle.area() << endl;

    cout << "Scale rectangle by 5" << endl;
    rectangle.scale(5);
    cout << "Rectangle area after scaling: " << rectangle.area() << endl;

    return 0;
}
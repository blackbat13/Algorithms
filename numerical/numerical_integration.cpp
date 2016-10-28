//
// Created by Damian Kurpiewski on 29.10.2016.
//

#include <iostream>

using namespace std;

/// Function to integrate
double f(double x) {
    return x * x + 2 * x;
}


/// Compute area under function f
///   from a to b using n rectangles
double rectangles_method(int a, int b, int n) {
    double rectangle_width = (b - a)/(double)n;
    double area = 0;
    double current_point = a;

    for(int i = 0; i < n; i++) {
        double rectangle_height;

        current_point += rectangle_width;
        rectangle_height = f(current_point);
        area += rectangle_height * rectangle_width;
    }

    return area;
}

/// Compute area under function f
///   from a to b using n trapezes
double trapezes_method(int a, int b, int n) {
    double trapeze_height = (b - a)/(double)n;
    double area = 0;
    double current_point = a;

    for(int i = 0; i < n; i++) {
        double trapeze_first_side;
        double trapeze_second_side;

        trapeze_first_side = f(current_point);
        current_point += trapeze_height;
        trapeze_second_side = f(current_point);

        area += ((trapeze_first_side + trapeze_second_side) * trapeze_height) / 2.0;
    }

    return area;
}

int main() {
    int a, b, n;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter n: ";
    cin >> n;

    cout << "Rectangles method result: " << rectangles_method(a,b,n) << endl;
    cout << "Trapezes method result: " << trapezes_method(a,b,n) << endl;

    return 0;
}
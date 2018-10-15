//
// Created by Damian Kurpiewski on 15/10/2018.
//

#include <iostream>
#include <cmath>

using namespace std;

/// Compute distance of the given point from the line given by two points
double pointLineDistance(double lineX1, double lineY1, double lineX2, double lineY2, double pointX, double pointY) {
    double a = lineY2 - lineY1;
    double b = lineX2 - lineX1;
    double result = abs(a * (lineX1 - pointX) + b * (pointY - lineY1)) / sqrt(a * a + b * b);
    return result;
}

int main() {
    double distance;
    distance = pointLineDistance(-3, -4, 7, 6, -5, -8);
    cout << "Distance of the point (-5, -8) from the line ((-3, -4), (7, 6)) is " << distance << endl;
    return 0;
}
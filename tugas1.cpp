#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
} 
//calculate distance

double radius(double x1, double y1, double x2, double y2) {
    return distance(x1, y1, x2, y2);
} 
//calculate radius

double circumference(double r) {
    const double pi = 3.1416;
    return 2 * pi * r;
} 
//calculate keliling

double area(double r) {
    const double pi = 3.1416;
    return pi * r * r;
} 
//calculate luaas

int main() {
    double x1, y1, x2, y2;

    cout << "Insert coordinates of the center of the circle (x1, y1): ";
    cin >> x1 >> y1; //input center

    cout << "Insert coordinates of a point on the circle (x2, y2): ";
    cin >> x2 >> y2; //input point

    double r = radius(x1, y1, x2, y2); //hitung radius

    cout << "Radius: " << r << endl;
    cout << "Diameter: " << 2 * r << endl;
    cout << "Circumference: " << circumference(r) << endl;
    cout << "Area: " << area(r) << endl; //outputnya

    return 0;
}
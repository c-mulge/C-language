#include <iostream>
#include <cmath>
using namespace std;

class Area 
{
private:
    double length, breadth, side, radius, base, height;

public:
    void area_rect() {
        cout << "Enter length and breadth of rectangle: ";
        cin >> length >> breadth;
        double area = length * breadth;
        cout << "Area of rectangle: " << area << endl;
    }

    void area_square() {
        cout << "Enter side of square: ";
        cin >> side;
        double area = side * side;
        cout << "Area of square: " << area << endl;
    }

    void area_circle() {
        cout << "Enter radius of circle: ";
        cin >> radius;
        double area = M_PI * radius * radius;
        cout << "Area of circle: " << area << endl;
    }

    void area_triangle() {
        cout << "Enter base and height of triangle: ";
        cin >> base >> height;
        double area = 0.5 * base * height;
        cout << "Area of triangle: " << area << endl;
    }
};

int main() {
    Area obj;
    int choice;

    do {
        cout << "\n1. Rectangle\n2. Square\n3. Circle\n4. Triangle\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.area_rect();
                break;
            case 2:
                obj.area_square();
                break;
            case 3:
                obj.area_circle();
                break;
            case 4:
                obj.area_triangle();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

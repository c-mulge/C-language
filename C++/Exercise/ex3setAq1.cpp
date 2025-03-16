//Write a C++ program using inline function to find square root and cube of a number.

#include <iostream>
#include <cmath> // Include the cmath header for the sqrt function
using namespace std;

// Inline function to find the square root
inline double findSquareRoot(double num) {
    return sqrt(num);
}

// Inline function to find the cube
inline double findCube(double num) {
    return num * num * num;
}

int main() {
    double number;

    // Input a number from the user
    cout << "Enter a number: ";
    cin >> number;

    // Calculate and display the square root using the inline function
    cout << "Square Root: " << findSquareRoot(number) << endl;

    // Calculate and display the cube using the inline function
    cout << "Cube: " << findCube(number) << endl;

    return 0;
}

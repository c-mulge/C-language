/*
Create a class named ‘DISTANCE‟ with: - feet and inches as data members.
The class has the following member functions:
i. To input distance
ii. To output distance
iii. To add two distance objects
Write a C++ program to create objects of DISTANCE class. Input two distances and output the sum.
*/

#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    // Function to input distance
    void inputDistance() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Function to output distance
    void outputDistance() {
        cout << "Distance: " << feet << " feet, " << inches << " inches" << endl;
    }

    // Function to add two distance objects
     Distance addDistance(Distance d) {
        Distance result;
        result.feet = feet + d.feet;
        result.inches = inches + d.inches;

        if (result.inches >= 12) {
            result.feet += result.inches / 12;
            result.inches %= 12;
        }

        return result;
    }
};

int main() {
    Distance distance1, distance2, sum;

    // Input two distances
    cout << "Enter details for Distance 1:\n";
    distance1.inputDistance();

    cout << "\nDetails for Distance 1:\n";
    distance1.outputDistance();

    cout << "\nEnter details for Distance 2:\n";
    distance2.inputDistance();

    cout << "\nDetails for Distance 2:\n";
    distance2.outputDistance();

    // Add the two distances
    sum = distance1.addDistance(distance2);

    // Output the sum of distances
    cout << "\nSum of the given two distance:\n";
    sum.outputDistance();

    return 0;
}

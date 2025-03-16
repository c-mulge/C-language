// Write a C++ program to subtract two integer numbers of two different classes using friend function.

#include <iostream>
using namespace std;

// Forward declaration of the SecondNumber class
class SecondNumber;

// FirstNumber class definition
class FirstNumber {
private:
    int num1;

public:
    // Function to set the value of num1
    void setNum1(int n) {
        num1 = n;
    }

    // Friend function declaration without const
    friend int subtract(FirstNumber&, SecondNumber&);
};

// SecondNumber class definition
class SecondNumber {
private:
    int num2;

public:
    // Function to set the value of num2
    void setNum2(int n) {
        num2 = n;
    }

    // Friend function declaration without const
    friend int subtract(FirstNumber&, SecondNumber&);
};

// Friend function definition without const
int subtract(FirstNumber& first, SecondNumber& second) {
    // Access private members of both classes
    return first.num1 - second.num2;
}

int main() {
    FirstNumber first;
    SecondNumber second;
    int num1, num2;

    // Accept input for the first number
    cout << "Enter the first number: ";
    cin >> num1;
    first.setNum1(num1);

    // Accept input for the second number
    cout << "Enter the second number: ";
    cin >> num2;
    second.setNum2(num2);

    // Call the friend function to subtract the numbers
    int result = subtract(first, second);

    // Display the result
    cout << "Result of subtraction: " << result << endl;

    return 0;
}



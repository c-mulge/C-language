#include<iostream>
using namespace std;
// //vol of cube= a**3
// //vol of cyl= pi*r**2*h
// //vol of sphere= 4/3*pi*r**3

// void vol(int a)
// {
//     cout<<a*a*a<<endl;
// }

// void vol(int r,int h)
// {
//     cout<<3.14*r*r*h<<endl;
// }

// void vol(double r)
// {
//     cout<<(4.0/3.0)*3.141592653589793*(r*r*r);
// }

// int main()
// {
//     vol(2);
//     vol(2,3);
//     vol(2.0);
//     return 0;
// }


class SimpleInterestCalculator {
public:
    // Function to calculate simple interest with rate of interest = 5
    int calculate(int p, int n, int r = 5) {
        return (p * n * r) / 100;
    }

    // Function to calculate simple interest with default values for n and r
    int calculate(int p, int n = 10, int r = 7) {
        return (p * n * r) / 100;
    }
};

int main() {
    SimpleInterestCalculator calculator;

    // Example 1: Using default rate of interest (r = 5)
    int si1 = calculator.calculate(1000, 2);
    cout << "Simple Interest (r=5): " << si1 << endl;

    // Example 2: Using default values for n and r (n = 10, r = 7)
    int si2 = calculator.calculate(1500);
    cout << "Simple Interest (n=10, r=7): " << si2 << endl;

    return 0;
}

// #include <iostream>

// class SimpleInterestCalculator {
// public:
//     // Function to calculate simple interest with rate of interest = 5
//     double calculate(int p, int n, int r = 5) {
//         return (p * n * r) / 100.0;
//     }

//     // Function to calculate simple interest with different default values for n and r
//     double calculate(int p, int n = 10, int r = 7) {
//         return (p * n * r) / 100.0;
//     }
// };

// int main() {
//     SimpleInterestCalculator calculator;

//     // Example 1: Using default rate of interest (r = 5)
//     double si1 = calculator.calculate(1000, 2,0);
//     std::cout << "Simple Interest (r=5): " << si1 << std::endl;

//     // Example 2: Using default values for n (n = 10) and a different default for r (r = 7)
//     double si2 = calculator.calculate(1500,0,0);
//     std::cout << "Simple Interest (n=10, r=7): " << si2 << std::endl;

//     return 0;
// }

// #include <iostream>

// // Template function to print any type
// template<typename T>
// void print(const T& value) {
//     std::cout << "Printing value: " << value << std::endl;
// }

// int main() {
//     print(42);           // int
//     print(3.14159);      // double
//     print("Hello");      // const char*

//     return 0;
// }

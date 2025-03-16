#include <iostream>

using namespace std;

class Calculator
{
private:
    double Number1, Number2;

public:
    Calculator() : Number1(0), Number2(0) {}

    void setNumbers(double num1, double num2)
    {
        if (num1 <= 0 || num2 <= 0)
        {
            throw "Numbers should be greater than 0!";
        }
        if (num1 < 500 || num1 > 1000 || num2 < 500 || num2 > 1000)
        {
            throw "Numbers should be in the range between 500 to 1000!";
        }
        Number1 = num1;
        Number2 = num2;
    }

    double addition()
    {
        return Number1 + Number2;
    }

    double multiplication()
    {
        return Number1 * Number2;
    }
};

int main()
{
    double num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    try
    {
        Calculator calc;
        calc.setNumbers(num1, num2);
        cout << "Addition: " << calc.addition() << endl;
        cout << "Multiplication: " << calc.multiplication() << endl;
    }
    catch (const char *msg)
    {
        cerr << "Error: " << msg << endl;
    }

    return 0;
}

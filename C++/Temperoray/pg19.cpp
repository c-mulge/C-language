#include <iostream>
using namespace std;

int main()
{
    double num1, num2, result;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    try
    {
        if (num2 == 0)
        {
            throw "Division by ze4ro error!";
        }
        else
        {
            result = num1 / num2;
            cout << "Result of division: " << result << endl;
        }
    }
    catch (const char *msg)
    {
        /*cerr*/ cout << "Error: " << msg << endl;
    }

    return 0;
}

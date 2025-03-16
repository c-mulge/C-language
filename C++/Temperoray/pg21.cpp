#include <iostream>
#include <cmath>

using namespace std;

double my_sqrt(double x)
{
    if (x < 0)
    {
        throw "Cannot compute square root of a negative number!";
    }
    return sqrt(x);
}

int main()
{
    double num;

    cout << "Enter a number: ";
    cin >> num;

    try
    {
        double result = my_sqrt(num);
        cout << "Square root of " << num << " is: " << result << endl;
    }
    catch (const char *msg)
    {
        cerr << "Error: " << msg << endl;
    }

    return 0;
}

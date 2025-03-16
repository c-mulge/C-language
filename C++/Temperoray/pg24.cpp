#include <iostream>
#include <stdexcept>

using namespace std;

unsigned long long factorial(int n)
{
    if (n < 0)
    {
        throw invalid_argument("Negative number exception: Factorial of a negative number is undefined.");
    }

    if (n > 20)
    {
        throw bad_alloc();
    }

    if (n == 0 || n == 1)
    {
        return 1;
    }

    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int number;

    cout << "Enter a number to find its factorial: ";
    cin >> number;

    try
    {
        unsigned long long result = factorial(number);
        cout << "Factorial of " << number << " is: " << result << endl;
    }
    catch (const invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const bad_alloc &e)
    {
        cerr << "Error: Out of memory exception. Cannot compute factorial for numbers greater than 20." << endl;
    }

    return 0;
}

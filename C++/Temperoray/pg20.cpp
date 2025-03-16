#include <iostream>
// #include <stdexcept>

using namespace std;

void printSuccessiveIntegers(int StopNum)
{
    if (StopNum <= 0)
    {
        throw invalid_argument("StopNum must be a positive integer.");
    }

    for (int i = 1; i < StopNum; ++i)
    {
        cout << i << endl;
    }

    throw StopNum; // Throw the stopping number as an exception
}

int main()
{
    int StopNum;

    cout << "Enter the stopping number: ";
    cin >> StopNum;

    try
    {
        printSuccessiveIntegers(StopNum);
    }
    catch (const invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (int stopNumException)
    {
        cerr << "Integer exception thrown with value: " << stopNumException << endl;
    }

    return 0;
}

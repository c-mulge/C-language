#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int age;
    string year;

public:
    void setInfo(const string &n, int a, const string &y)
    {
        if (a < 18 || a > 25)
        {
            throw "Age should be between 18 and 25!";
        }
        if (y != "FY" && y != "SY" && y != "TY")
        {
            throw "Invalid year! Year should be 'FY', 'SY', or 'TY'.";
        }
        name = n;
        age = a;
        year = y;
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Year: " << year << endl;
    }
};

int main()
{
    string name, year;
    int age;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter student age: ";
    cin >> age;

    cin.ignore(); // Ignore the newline character

    cout << "Enter student year (FY, SY, TY): ";
    getline(cin, year);

    try
    {
        Student student;
        student.setInfo(name, age, year);
        student.displayInfo();
    }
    catch (const char *msg)
    {
        cerr << "Error: " << msg << endl;
    }

    return 0;
}

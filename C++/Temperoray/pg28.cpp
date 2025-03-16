#include <iostream>
using namespace std;
class work
{
    char a[30];
    int no;
    double pay;

public:
    work(char name[], int no_day, double amt)
    {
        a = name;
        no = no_day;
        pay = amt;
    }
    void salary()
    {
        double a;
        a = no * pay;
        cout << "Salary: " << a << endl;
    }
    ~work()
    {
        cout << "Free" << endl;
    }
};

int main()
{
    work w;
    char name[20];
    int no;
    double amt;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter no: ";
    cin >> no;
    cout << "Enter amt: ";
    cin >> amt;
    work w1(name, no, amt);
    w1.salary();
    return 0;
}
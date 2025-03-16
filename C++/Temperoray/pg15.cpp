// ex-7 set b q.2.

#include <iostream>
#include <iomanip>
using namespace std;

class Person
{
private:
    char f_name[20];
    char l_name[20];

public:
    void accept()
    {
        cout << "Enter First Name:";
        cin >> f_name;
        cout << "Enter Last Name:";
        cin >> l_name;
    }
    void display()
    {
        cout << "First Name: " << f_name << endl;
        cout << "Last Name: " << l_name << endl;
    }
};

class Employee : public Person
{
public:
    int emp_id;
    int jdate;
    void accept()
    {
        Person::accept();
        cout << "Enter employee Id: ";
        cin >> emp_id;
        cout << "Jooining date: ";
        cin >> jdate;
    }
    void display()
    {
        Person::display();
        cout << "Employee Id: " << emp_id << endl;
        cout << "Joining Date: " << jdate << endl;
    }
};

class Emp_sal : public Employee
{
public:
    int TA, DA, Bonus;
    void accept()
    {
        Employee::accept();
        cout << "Enter TA: ";
        cin >> TA;
        cout << "Enter DA: ";
        cin >> DA;
        cout << "Enter Bonus: ";
        cin >> Bonus;
    }
    double netsalary()
    {
        return TA + DA + Bonus;
    }
    void SSlip()
    {
        cout << "--------------------" << endl;
        Employee::display();
        cout << fixed << setprecision(2);
        cout << "TA: ₹" << TA << endl;
        cout << "DA: ₹" << DA << endl;
        cout << "Bonus: ₹" << Bonus << endl;
        cout << "Net Salary: ₹" << netsalary() << endl;
        cout << "--------------------" << endl;
    }
};

int main()
{
    Emp_sal emp;
    emp.accept();
    emp.SSlip();
    return 0;
}
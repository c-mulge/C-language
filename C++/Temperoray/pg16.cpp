// // Single ingheritance

// #include <iostream>
// using namespace std;

// class num
// {
// protected:
//     int a, b;

// public:
//     void getdata()
//     {
//         cout << "Enter the values for a & b: ";
//         cin >> a >> b;
//     }
// };

// class add : public num
// {
// private:
//     int sum;

// public:
//     void addnum()
//     {
//         num::getdata();
//         sum = a + b;
//     }
//     void display()
//     {
//         cout << "The sum is: " << sum;
//     }
// };

// int main()
// {
//     add a;
//     a.addnum();
//     a.display();
//     return 0;
// }

// #include <iostream>
// #define pi 3.14
// using namespace std;

// class rad
// {
// protected:
//     float radius;

// public:
//     void getdata()
//     {
//         cout << "Enter radius of circle: ";
//         cin >> radius;
//     }
// };

// class area : public rad
// {
// private:
//     double areaofc;

// public:
//     void areac()
//     {
//         rad::getdata();
//         areaofc = pi * radius * radius;
//     }
//     void display()
//     {
//         cout << "Area of circle: " << areaofc << endl;
//     }
// };

// int main()
// {
//     area a;
//     a.areac();
//     a.display();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int top = 3;

// class base
// {
// protected:
//     int top;

// public:
//     base()
//     {
//         top = 2;
//         cout << endl
//              << top;
//     }
// };

// class derived : public base
// {
// private:
//     int top;

// public:
//     derived() : base()
//     {
//         top = 1;
//         cout << endl
//              << top;
//         cout << endl
//              << base::top;
//         cout << endl
//              << ::top;
//     }
// };

// int main()
// {
//     derived dl;
//     return 0;
// }

#include <iostream>
using namespace std;

class account
{
protected:
    char name[20];
    int acc_no;
};

class saving : public account
{
private:
    float rofi;

public:
    void accept()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Account no: ";
        cin >> acc_no;
        cout << "Rate of Interest: ";
        cin >> rofi;
    }

    void display()
    {
        cout << "--------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Account no: " << acc_no << endl;
        cout << "Rate of Interest: " << rofi << endl;
    }
};

int main()
{
    int n, i;
    saving s[100];
    cout << "Enter n numbers: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        s[i].accept();
    }
    cout << "Details: " << endl;
    for (i = 0; i < n; i++)
    {
        s[i].display();
    }
    cout << "-----------------------------" << endl;
    return 0;
}


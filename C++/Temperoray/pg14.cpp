// ex-6 set-a q.1.
#include <iostream>
using namespace std;

class space
{
    int x, y;

public:
    void getdata(int a, int b)
    {
        x = a;
        y = b;
    }
    void display()
    {
        cout << x << endl;
        cout << y << endl;
    }
    void operator++();
    void operator++(int);
};

void space::operator++()
{
    ++x;
    ++y;
}

void space::operator++(int)
{
    x++;
    y++;
}

int main()
{
    space s;
    s.getdata(10, 11);
    s.display();
    ++s;
    s.display();
    cout << "-------------------------" << endl;
    s++;
    s.display();
    return 0;
}

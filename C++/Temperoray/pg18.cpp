// operation overloading
#include <iostream>
using namespace std;

class Marks
{
    int mark;

public:
    Marks()
    {
        mark = 0;
    }
    Marks(int m)
    {
        mark = m;
    }

    void show()
    {
        cout << "Your mark are: " << mark << endl;
    }

    void operator+=(int extra)
    {
        mark = mark + extra;
    }
    friend void operator-=(Marks &obj, int red);
};

void operator-=(Marks &obj, int red)
{
    obj.mark -= red;
}

int main()
{
    Marks m1(45);
    m1.show();
    m1 += 20;
    m1.show();
    m1 -= 20;
    m1.show();
    return 0;
}
// unary operator overloading
#include <iostream>
using namespace std;

class num
{
    int x, y;

public:
    void accept()
    {
        cout << "Enter x and y: ";
        cin >> x >> y;
    }
    void operator-()
    {
        x = -x;
        y = -y;
    }
    void display()
    {
        cout << "X= " << x << " Y= " << y << endl;
    }
};

int main()
{
    num n;
    n.accept();
    n.display();
    -n;
    n.display();
    return 0;
}
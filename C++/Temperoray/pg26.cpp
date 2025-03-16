#include <iostream>
using namespace std;

class Number
{
    int x, y;

public:
    Number()
    {
        cout << "Enter x any y: ";
        cin >> x >> y;
        cout << "X: " << x << " Y: " << y << endl;
    }
    Number(int a, int b)
    {
        x = a;
        y = b;
    }
    void comp()
    {
        if (x > y)
        {
            cout << "Max: " << x << endl;
        }
        else
        {
            cout << "Max: " << y << endl;
        }
    }
};

int main()
{
    Number num;
    int a, b;
    cout << "Enter two values: ";
    cin >> a >> b;
    Number num2(a, b);
    num.comp();
    num2.comp();
    return 0;
}
// Increment and decrement
#include <iostream>
using namespace std;
class number
{
    int x, y;

public:
    void accept()
    {
        cout << "Enter x and y: ";
        cin >> x >> y;
    }
    void display()
    {
        cout << "X= " << x << " Y= " << y << endl;
    }
    void operator++()
    {
        x++;
        y++;
    }
    void operator--(int)
    {
        x--;
        y--;
    }
};

int main()
{
    number n;
    n.accept();
    n.display();
    ++n; // Pre-Increment
    n.display();
    n--; // Post-Increment
    n.display();
    return 0;
}
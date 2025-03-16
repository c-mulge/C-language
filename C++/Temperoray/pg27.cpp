#include <iostream>
using namespace std;

class cal
{
    double pri, time, rate;

public:
    cal(double p, double t, double r = 0.5)
    {
        pri = p;
        time = t;
        rate = r;
    }
    double calculate()
    {
        return (pri * time * rate) / 100;
    }
};

int main()
{
    cal c(100, 500);
    double si = c.calculate();
    cout << "SI: " << si << endl;
    return 0;
}
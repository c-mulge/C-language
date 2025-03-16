#include <iostream>
using namespace std;
template <typename x>
x add(x a, x b)
{
    return (a + b);
}

int main()
{
    cout << add(3.5, 5.2) << endl;
    return 0;
}
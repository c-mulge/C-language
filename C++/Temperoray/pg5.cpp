#include <iostream>

using namespace std;

int main()
 {
    // Declare variables
    int n, num = 1;

    // Input the num of rows from the user
    cout << "Enter the num of rows for Floyd's triangle: ";
    cin >> n;

    // Print Floyd's triangle
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << num << " ";
            ++num;
        }
        cout << endl;
    }

    return 0;
}
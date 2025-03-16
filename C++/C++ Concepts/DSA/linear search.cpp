// linear search or sequential search

#include <iostream>
#define maxsz 15
using namespace std;

int linear(int a[], int n, int key)
{
    int i;
    for (i = 0; i < n && a[i] < key; i++)
        ;
    if (a[i] == key)
        return i;
    return -1;
}

int main()
{
    int n, i, key, res;
    int a[maxsz];
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "enter elements in array: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter key to find: ";
    cin >> key;
    res = linear(a, n, key);
    if (res != -1)
    {
        cout << "The key " << key << " is at " << res << " index" << endl;
    }
    else
    {
        cout << "The key " << key << " is not in the given array" << endl;
    }
    return 0;
}
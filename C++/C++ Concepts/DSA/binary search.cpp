// Binary search
// Binary search requires a sorted data to find key
#include <iostream>
#define maxsz 15
using namespace std;

int binary(int a[], int lb, int ub, int key)
{
    int mid;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid]
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return -1;
}

/*This code snippet implements a binary search algorithm to
find the index of a given key in a sorted array.
It returns the index of the key if found, otherwise returns -1.*/

void accept(int a[], int n)
{
    int i, j, hold;
    for (i = 0; i < n; i++)
    {
        cin >> hold;
        for (j = i - 1; j >= 0 && hold < a[j]; j--)
            a[j + 1] = a[j];
        a[j + 1] = hold;
    }
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int n, a[maxsz];
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements in array: ";
    accept(a, n);
    display(a, n);
    cout << "Enter key to find: ";
    int key;
    cin >> key;
    int res = binary(a, 0, n - 1, key);
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

/*This code snippet defines the main function in C++.
It prompts the user to enter the size of an array,
then the elements of the array, and a key to find within the array using a binary search algorithm.
It then displays the index of the key if found, or a message indicating that the key is not in the array.*/
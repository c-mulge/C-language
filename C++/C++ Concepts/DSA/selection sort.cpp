// Selection sort

#include <iostream>
using namespace std;
/*
void selectionsort(int a[], int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i]) // just change the sign to make code descending
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}*/

/* It sorts an array of integers in ascending order by
repeatedly finding the minimum element from the unsorted
part of the array and swapping it with the first unsorted element.*/

void selection(int arr[], int n)
{
    int small, s, count;
    for (int i = 0; i < n - 1; i++)
    {
        small = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < small)
            {
                small = arr[j];
                s = j;
                count = 1;
            }
        }
        if (count == 1)
        {
            arr[s] = arr[i];
            arr[i] = small;
        }
        count = 0;
    }
}

int main()
{
    int n, i;
    cout << "Enter size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter array: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // selectionsort(a, n);
    selection(a, n);
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
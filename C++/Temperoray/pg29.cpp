#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define maxsz 50
using namespace std;

// int main()
// {
//     int a, b, c;
//     cout << "Enter value for a, b, c: ";
//     cin >> a >> b >> c;
//     if (a >= b && a >= c)
//         cout << "A is largest";
//     else if (b >= c && b >= a)
//         cout << "B is largest";
//     else
//         cout << "C is largest";
//     return 0;
// }

// int main()
// {
//     int a, b, c;
//     cout << "Enter value for a, b, c: ";
//     cin >> a >> b >> c;
//     int ans;
//     ans = max(a, max(b, c));
//     cout << ans << " is the largest";
//     return 0;
// }

// bool check(int year)                             //leap year or not
// {
//     if (year % 400 == 0)
//         return true;
//     else if (year % 100 == 0)
//         return false;
//     else if (year % 4 == 0)
//         return true;
//     else
//         return false;
// }

// int main()
// {
//     int year;
//     cout << "Enter year: ";
//     cin >> year;
//     check(year) ? cout << "Leap Year" : cout << "Not a leap year";
//     return 0;
// }

// bool isprime(int n)                               //check wheather the given number is prime number
// {
//     if (n <= 1)
//         return false;

//     for (int i = 2; i <= n / 2; i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }

// int main()
// {
//     int a;
//     cout << "enter num: ";
//     cin >> a;
//     isprime(a) ? cout << "It is Prime" : cout << "It is not prime";
//     return 0;
// }

// int chk(string str)                          //check palindrome
// {
//     int len = str.length();
//     for (int i = 0; i < len / 2; i++)
//     {
//         if (str[i] != str[len - i - 1])
//             return false;
//     }
//     return true;
// }

// int main()
// {
//     string st;
//     cout << "Enter string: ";
//     cin >> st;
//     if (chk(st) == true)
//         cout << "Yes";
//     else
//         cout << "No";
//     return 0;
// }

// int main()                             //basic calculator
// {
//     int a, b;
//     cout << "Enter value for a & b: ";
//     cin >> a >> b;
//     int choice;
//     while (1)
//     {
//         cout << "Enter + for addition" << endl;
//         cout << "Enter - for subtraction" << endl;
//         cout << "Enter * for multiplication" << endl;
//         cout << "Enter / for division" << endl;
//         cout << "Enter 5 to exit the program" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice)
//         {
//         case '+':
//             cout << "Addition is: " << a + b << endl;
//             break;
//         case '-':
//             cout << "Subtraction is: " << a - b << endl;
//             break;
//         case '*':
//             cout << "Multiplication is: " << a * b << endl;
//             break;
//         case '/':
//             cout << "Division is: " << a / b << endl;
//             break;
//         case 5:
//             exit(1);
//             break;
//         default:
//             cout << "Invalid choice" << endl;
//             break;
//         }
//     }
//     return 0;
// }

// void rev(char *str, int index, int n)                 //reverse the string
// {
//     if (index == n)
//         return;

//     char temp = str[index];
//     rev(str, index + 1, n);
//     cout << temp;
// }

// int main()
// {
//     char a[] = "Hello World, how are you";
//     int n = sizeof(a) / sizeof(a[0]);
//     rev(a, 0, n);
//     return 0;
// }

// int fib(int n)                               //fibonaci series
// {
//     if (n <= 1)
//         return n;
//     return fib(n - 1) + fib(n - 2);
// }

// int main()
// {
//     int n = 10;
//     cout << "Output: " << fib(n) << endl;
//     return 0;
// }

// template <typename T>                                   //swap using template
// void swap_fun(T &a, T &b)
// {
//     T temp = a;
//     a = b;
//     b = temp;
// }

// int main()
// {
//     int a, b;
//     cin >> a >> b;
//     cout << "Before: " << a << " " << b << endl;
//     swap_fun(a, b);
//     cout << "After: " << a << " " << b << endl;
//     return 0;
// }

void bubble(int a[], int n) // check if 2 arrays are equal or not
{
    int swapping = 1;
    int temp, i, j;
    for (i = 1; i < n && swapping; i++)
    {
        swapping = 0;
        for (j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swapping = 1;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// bool check(int a[], int b[], int n, int m)
// {
//     int i;
//     if (n != m)
//     {
//         return false;
//     }
//     for (i = 0; i < n; i++)
//     {
//         if (a[i] != b[i])
//             return false;
//     }
//     return true;
// }

// int main()
// {
//     int a[maxsz], b[maxsz];
//     int n, m, i;
//     cout << "Enter size of first array: ";
//     cin >> n;
//     cout << "Enter the numbers for array : ";
//     for (i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     cout << "Enter size of second array: ";
//     cin >> m;
//     cout << "Enter the numbers for array : ";
//     for (i = 0; i < m; i++)
//     {
//         cin >> b[i];
//     }
//     bubble(a, n);
//     bubble(b, n);

//     if (check(a, b, n, m))
//     {
//         cout << "equal" << endl;
//     }
//     else
//     {
//         cout << "not equal" << endl;
//     }
//     return 0;
// }

// void avg(int a[], int n) // find average using iterative aapproach
// {
//     int i;
//     float sum = 0, total;
//     for (i = 0; i < n; i++)
//     {
//         sum += a[i];
//     }
//     total = sum / n;
//     cout << "Average is: " << total << endl;
// }

// int main()
// {
//     int a[maxsz];
//     int n, i;
//     cout << "Enter size of first array: ";
//     cin >> n;
//     cout << "Enter the numbers for array : ";
//     for (i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     avg(a, n);
//     return 0;
// }

// int getmin(int a[], int n)                    // find max and min from the array
// {
//     return *min_element(a, a + n);
// }

// int getmax(int a[], int n)
// {
//     return *max_element(a, a + n);
// }

// int main()                                  //--logic 1
// {
//     int a[] = {12, 1, 45, 67, 1};
//     int n = sizeof(a) / sizeof(a[0]);
//     cout << "Minimum: " << getmin(a, n) << " Maximum: " << getmax(a, n);
//     return 0;
// }

// int main() //--logic 2
// {
//     int a[maxsz];
//     int n, i;
//     cout << "Enter size of first array: ";
//     cin >> n;
//     cout << "Enter the numbers for array : ";
//     for (i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     bubble(a, n);
//     cout << "Minimum: " << a[0] << " Maximum: " << a[n - 1];
// }

// int linear(int a[], int n, int key)
// {
//     int i;
//     for (i = 0; i < n && a[i] < key; i++)
//         ;
//     if (a[i] == key)
//         return i;
//     return -1;
// }

// int main()
// {
//     int a[maxsz];
//     int n, i;
//     cout << "Enter size of array: ";
//     cin >> n;
//     cout << "Enter the content for array : ";
//     for (i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int key;
//     cout << "Enter key: ";
//     cin >> key;
//     int res = linear(a, n, key);
//     if (res == -1)
//     {
//         cout << "Not found" << endl;
//     }
//     else
//     {
//         cout << "Found at index " << res << endl;
//     }
//     return 0;
// }

// int linear(int a[], int n, int key)
// {
//     int i;
//     for (i = 0; i < n; i++)
//         if (a[i] == key)
//             return i;
//     return -1;
// }

// int main()
// {
//     int n, i, key, res;
//     int a[maxsz];
//     cout << "Enter the size of array: ";
//     cin >> n;
//     cout << "enter elements in array: ";
//     for (i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout << "Enter key to find: ";
//     cin >> key;
//     res = linear(a, n, key);
//     if (res != -1)
//     {
//         cout << "The key " << key << " is at " << res << " index" << endl;
//     }
//     else
//     {
//         cout << "The key " << key << " is not in the given array" << endl;
//     }
//     return 0;
// }

// array after it is rotated k times

// void rotate(int a[], int n, int k)
// {
//     k = k % n;
//     for (int i = 0; i < n; i++)
//     {
//         if (i < k)
//         {
//             cout << a[n + i - k] << " ";
//         }
//         else
//         {
//             cout << a[i - k] << " ";
//         }
//     }
//     cout << "\n";
// }

// int main()
// {
//     int a[maxsz];
//     int n, i, k;
//     cout << "Enter size of array: ";
//     cin >> n;
//     cout << "Enter the content for array : ";
//     for (i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout << "Enter k: ";
//     cin >> k;
//     rotate(a, n, k);
//     return 0;
// }
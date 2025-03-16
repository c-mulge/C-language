// #include <iostream>
// using namespace std;  /*here namespace std is used as universal namespace definer it will be used everywhere
// were cout is called*/

// int main()
// {
//     cout<<"Hello world"<<endl;  
//      //cout is used to call out, it works as printf from C language 
//      //<<endl is used to break line 
//     cout<<"next line";

    
//     return 0;
// }

#include<iostream>
#define maxsz 10

void bubblesort(int a[], int n)
{
    int temp;
    int i, j, swapping = 1;
    for (i = 1; i < n && swapping; i++)
    {
        swapping = 0;
        for (j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1]) // Change the sign to make the code in descending order
            {
                swapping = 1; // If true, swapping is necessary
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[maxsz];
    int n, i;
    std::cout << "How many numbers: ";
    std::cin >> n;

    std::cout << "Enter " << n << " numbers: \n";
    for (i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    bubblesort(a, n);
    std::cout << "Sorted: \n";
    for (i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;
}

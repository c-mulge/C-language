//Write a C++ program to print right oriented right-angled pyramid.

#include <iostream>
using namespace std;

// int main()
// {
//     int i, j, k = 1;
//     int rows;
//     cout << "Enter the number of rows: ";
//     cin >> rows;
//     for (i = 1; i <= rows; i++) 
//     {
//         for (k = i; k < rows; k++) 
//         {
//             cout << "\t";
//         }
//         for (j = 1; j <= i; j++) 
//         {
//             cout << k << "\t";
//             k++;
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// int main()                     //rectangle star pattern
// {
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// int main()              //hollow rectangle
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             if(i==1||i==n||j==1||j==n)
//             {
//                 cout<<"*";
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }

// int main()              //hollow rectangle
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             if(i==1||i==n||j==1||j==n)
//             {
//                 cout<<"*";
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }

// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=1; i<=n; i++)
//     {
//         for(int j=1; j<=n+1-i; j++)
//         {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

int main()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if((i+j)%2==0)
            {
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
    return 0;
}
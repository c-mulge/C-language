// take n size from user and find max and min

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n size: ";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int maxno=a[n-1];
    int minno=a[0];
    for(int i=0;i<n;i++)
    {
        maxno=max(maxno,a[i]);
        minno=min(minno,a[i]);
        /*if(a[i]>max)
        {
            max=a[i];
        }
        if(a[i]<min)
        {
            min=a[i];
        }*/
    }
    cout<<"Max: "<<maxno<<" Min: "<<minno<<endl;
    return 0;
}
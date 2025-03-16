//Linear search in C++

#include<iostream>
#define maxsz 50
using namespace std;

int lin(int a[],int n,int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if(a[i]==key)
        {
            return i;
        }
    }      
    return -1;
}

int binary(int a[],int lb,int ub,int key)
{
    int mid;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
                ub=mid-1;
            else
                lb=mid+1;
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int a[maxsz];
    cout<<"Enter "<<n<<" numbers: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cout<<"Enter the key to find: ";
    cin>>key;
    int res=binary(a,0,n-1,key);
    if(res!=-1)
    {
        cout<<"The key "<<key<<" is at "<<res<<" index"<<endl;
    }
    else{
        cout<<"The key "<<key<<" is not in the given array"<<endl;
    }
    return 0;
}
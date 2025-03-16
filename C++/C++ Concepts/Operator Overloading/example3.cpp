//adding two obj
#include<iostream>
using namespace std;

class num
{
    int x,y;
    public:
        void accept()
        {
            cin>>x>>y;
        }
        void operator +(num n1,num n2)
        {
            num n;
            n.x=n1.x+n2.x;
            n.y=n1.y+n2.y;
        }
        void display()
        {
            cin>>
        }
}
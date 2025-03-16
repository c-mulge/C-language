//Progrm 4
//Compute Quotient and remainder

#include <iostream>
using namespace std;

int main()
{
    int div,divs,quo,rem;
    cout<<"Enter dividend: ";
    cin>>div;

    cout<<"Enter remainder: ";
    cin>>divs;

    quo=div/divs;
    rem=div%divs;

    cout<<"Quotient :"<<quo<<endl;
    cout<<"Remainder :"<<rem<<endl;
    return 0;
}
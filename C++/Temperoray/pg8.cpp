//trail and run programs----------------------------------------------------------------

// int main()
// {
//         cout.fill('<');
//         cout.precision(3);
//         for(int k=1;k<=6;k++)
//         {
//             cout.width(5);
//             cout<<k;
//             cout.width(10);
//             cout<<1.0/float(k)<<"\k";
//             if(k==3)
//             cout.fill('>');
//         }
//         cout<<"in padding changed\k\k";
//         cout.fill('#');
//         cout.width(15);
//         cout<<12.345678<<"\k";
//         return 0;
// }

// #include<iostream>
// #include<math.h>
// using namespace std;

// int main()
// {
//     int i, fact=1, sign=-1;
//     float x,num,sum,term;
//     cout<<"Enter an angle in degree: ";
//     cin>>x;
//     x=x*3.14/180;       //formula
//     term=x;
//     sum=term;
//     for(i=3;term>=0.000001;i=i+2)
//     {
//         fact=fact*i*(i-1);
//         num=pow(x,i);
//         term=num/fact;
//         sum=sum+sign*term;
//         sign=sign*-1;
//     }
//     cout<<"The value of the series is: "<<sum;
// }

// int main()
// {
//     int row,i;
//     cout<<"Rows: ";
//     cin>>row;
//     for(i=1;i<=row;i++)
//     {
//         for(int j=1;j<=i;j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// int main()
// {
//     int i,j,k;
//     cout<<"ENter the number of  * in the center line: ";
//     cin>>k;
//     for(i=1;i<=k;i++)
//     {
//         for(j=1;j<=k-i;j++)
//         {
//             cout<<" ";
//         }
//         for(j=1;j<=i;j++)
//         {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     for(i=k;i>=1;i--)
//     {
//         for(j=1;j<=k-i;j++)
//         {
//             cout<<" ";
//         }
//         for(j=1;j<=i;j++)
//         {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

// int main()
// {
//     int i,j,k;
//     cout<<"Enter the number of lines in the upper hailf: ";
//     cin>>k;
//     for(i=1;i<=k;i++)
//     {
//         for(j=1;j<=k-i;j++)
//         {
//             cout<<" ";
//         }
//         for(j=1;j<=2*i-1;j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     for(i=k-1;i>=1;i--)
//     {
//         for(j=1;j<=k-i;j++)
//         {
//             cout<<" ";
//         }
//         for(j=1;j<=2*i-1;j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// int main()
// {
//     int n,rev=0,digit;
//     cout<<"Enter a number: ";
//     cin>>n;
//     while(n!=0)
//     {
//         digit=n%10;
//         n=n/10;
//         rev=rev*10+digit;
//     }
//     cout<<"The rev number is: "<<rev;
//     return 0;
// }

// #include<iostream>           //addition function
// using namespace std;
// int print(int num)
// {
//     cout<<num<<endl;
//     return 0;
// }
// int add(int num1, int num2)
// {
//     print(num1);
//     print(num2);
//     int sum=num1+num2;
//     return sum;
// }
// int main()
// {
//     int num1, num2;
//     cout<<"Enter num1 and num2: ";
//     cin>>num1>>num2;
//     cout<<"Sum of num1 & num2 is: "<<add(num1,num2)<<endl;
//     //  "<<res<<endl;int res=add(num1,num2);
//     // cout<<"Sum of num1 & num2 is:
//     return 0;
// }

// #include<iostream>    //finding prime no from a given range
// #include<math.h>
// using namespace std;
// bool isPrime(int n)
// {
//     for(int i=2;i<=sqrt(n);i++)
//     {
//         if(n%i==0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }
// int main()
// {
//     int a,b;
//     cout<<"Enter 2 numbers: ";
//     cin>>a>>b;
//     for(int i=a;i<=b;i++)
//     {
//         if(isPrime(i))
//         {
//             cout<<"Prime no are: "<<i<<endl;
//         }
//     }
// }

// #include<iostream>        //prints fibonacci numbers
// using namespace std;
// void fib(int n)
// {
//     int num1=0,num2=1,next;
//     for(int i=1;i<=n;i++)
//     {
//        cout<<num1<<endl;
//        next=num1+num2;
//        num1= num2;
//        num2=next;
//     }
//     return;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     fib(n);
//     return 0;
// }

// #include<iostream>         //finding factorial of given num.
// using namespace std;
// int fact(int n)
// {
//     int f=1;
//     for(int i=2;i<=n;i++)
//     {
//         f*=i;
//     }
//     return f;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int ans=fact(n);
//     cout<<"Factorial of "<<n<<" is : "<<ans<<endl;
//     return 0;
// }

// #include<iostream>    //Q.1 sum of 1st n natural numbers
// #include<bits/stdc++.h>
// using namespace std;
// int sum(int n)
// {
//     int sum=0;
//     for(int i=0; i<=n; i++)
//     {
//         sum+=i;
//     }
//     // for(int i=0; i<=n; i++)
//     // {
//     //     sum=a(a+i)/2;
//     // }
//     return sum;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     cout<<sum(n)<<endl;
//     return 0;
// }


// #include<iostream>        //check wheather given nums are pythagorian triplet or not
// using namespace std;
// bool check(int x, int y, int z)
// {
//     int a=max(x,max(y,z));
//     int b,c;
//     if(a==x)
//     {
//         b=y;
//         c=z;
//     }
//     else if(a==y)
//     {
//         b=x;
//         c=z;
//     }
//     else{
//         b=x;
//         c=y;
//     }
//     if(a*a==b*b+c*c)
//     {
//         return 1;
//     }
//     return 0;
// }
// int main()
// {
//     int x,y,z;
//     cin>>x>>y>>z;
//     if(check(x,y,z))
//     {
//         cout<<"It is a pythagorian triplet";
//     }
//     else{
//         cout<<"It is not a pythagorian triplet";
//     }
//     return 0;
// }

#include<iostream>        
using namespace std;

int btod(int n)      //binary to decimal
{
    int ans=0;
    int x=1;
    while(n>0)
    {
        int y=n%10;
        ans+=x*y;
        x*=2;
        n/=10;
    }
    return ans;
}

int otod(int n)    //octal to decimal
{
    int ans=0;
    int x=1;
    while(n>0)
    {
        int y=n%10;
        ans+=x*y;
        x*=8;
        n/=10;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    cout<<otod(n)<<endl;
    return 0;
}

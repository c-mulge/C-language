//set-b Q.2.
#include<iostream>
#include<string.h>
using namespace std;

class player
{
private:
    int p_no;
    char p_name[30];
    int no_matches;
    int* matchesArray;
public:
    // player(int a,const char *b,int c): p_no(a), no_matches(c)
    // {
    //     strncpy(p_name, b, sizeof(p_name) - 1);
    //     p_name[sizeof(p_name) - 1] = '\0';
    //     matchesArray = new int[c];
    // }
    player(int a, const char* b, int c) : p_no(a), no_matches(c)
    {
        strcpy(p_name, b);
        matchesArray = new int[c];
    }

    ~player();
    void accept()
    {
        cout<<"Enter player number: ";
        cin>>p_no;
        cout<<"Enter player name: ";
        cin>>p_name;
        cout<<"Enter no. of matches: ";
        cin>>no_matches;
        matchesArray = new int[no_matches];
        cout << "Enter number of matches done in each match:" <<endl;
        for (int i = 0; i < no_matches; ++i) {
            cout << "Match " << i + 1 << ": ";
            cin >> matchesArray[i];
        }
    }
    void display()
    {
    cout << "Player Number: " << p_no <<endl;
    cout << "Player Name: " << p_name <<endl;
    cout << "Number of Matches: " << no_matches <<endl;
    cout << "Matches done in each match:" <<endl;
        for (int i = 0; i < no_matches; ++i) 
        {
            cout << "Match " << i + 1 << ": " << matchesArray[i] <<endl;
        }
    }
};


player::~player()
{
    delete[] matchesArray;
}


int main()
{
    player player1(1, "John Doe", 3);
    player1.accept();
    cout << "\nPlayer Details:" <<endl;
    player1.display();
    return 0;
}
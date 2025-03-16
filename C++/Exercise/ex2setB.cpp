/* Write a C++ program to create a Account class having Account_no, Owner_name, Account_type , Amount. 
For displaying details use appropriate manipulators. The program should contain following :
1. Accept details of n Accounts.
2. Display details of n Accounts.
*/

#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int account_no;
    string owner_name;
    string account_type;
    double amount;

public:
    void setDetails(int acc_no, const string& owner, const string& type, double amt) {
        account_no = acc_no;
        owner_name = owner;
        account_type = type;
        amount = amt;
    }

    void displayDetails() {
        cout << "Account No: " << account_no << endl;
        cout << "Owner Name: " << owner_name << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Amount: " << amount << endl;
        cout << "-----------------------------------------------\n";
    }
};

int main() {
    int n;

    cout << "Enter the number of accounts: ";
    cin >> n;

    Account* accounts = new Account[n];

    for (int i = 0; i < n; ++i) {
        int acc_no;
        string owner, type;
        double amt;

        cout << "\nEnter details for Account " << i + 1 << ":\n";
        cout << "Account No: ";
        cin >> acc_no;

        cout << "Owner Name: ";
        cin.ignore(); // Ignore newline character in the buffer
        getline(cin, owner);

        cout << "Account Type: ";
        cin >> type;

        cout << "Amount: ";
        cin >> amt;

        accounts[i].setDetails(acc_no, owner, type, amt);
    }

    cout << "\nDetails of " << n << " Accounts:\n";

    for (int i = 0; i < n; ++i) {
        accounts[i].displayDetails();
    }

    delete[] accounts; // Don't forget to release the allocated memory

    return 0;
}

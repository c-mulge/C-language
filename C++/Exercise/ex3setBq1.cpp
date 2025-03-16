/*
Consider a mall having various types of items for sale.
Create two classes named Electronics_Items and Sports_Items containing data member 
as total_amount in each class.
1. Create object of each class.
2. Use friend function to add total amount of both classes and print
the addition of amounts in main function.
*/

#include <iostream>
#include <string>
using namespace std;

class Sports_Items; // Forward declaration for Sports_Items class

// Electronics_Items class definition
class Electronics_Items {
public:
    string name;
    int total_amount;

    Electronics_Items() {
        total_amount = 0;
    }

    void setName(const string& itemName) {
        name = itemName;
    }

    void setTotalAmount(int amount) {
        total_amount = amount;
    }

    friend int getTotalAmount(const Electronics_Items&, const Sports_Items&);
};

// Sports_Items class definition
class Sports_Items {
public:
    string name;
    int total_amount;
    
    Sports_Items() {
        total_amount = 0;
    }

    void setName(const string& itemName) {
        name = itemName;
    }

    void setTotalAmount(int amount) {
        total_amount = amount;
    }

    friend int getTotalAmount(const Electronics_Items&, const Sports_Items&);
};

// Friend function definition to add total amounts of both classes
int getTotalAmount(const Electronics_Items& electronics, const Sports_Items& sports) {
    return electronics.total_amount + sports.total_amount;
}

int main() {
    // Accept the number of electronics and sports items
    int numElectronics, numSports;

    cout << "Enter the number of Electronics items: ";
    cin >> numElectronics;

    cout << "Enter the number of Sports items: ";
    cin >> numSports;

    // Create arrays to store objects
    Electronics_Items electronicsItems[numElectronics];
    Sports_Items sportsItems[numSports];

    // Accept input for the details of each electronics item
    for (int i = 0; i < numElectronics; ++i) {
        string itemName;
        int electronicsAmount;

        cout << "Enter name for Electronics item " << i + 1 << ": ";
        cin >> itemName;
        electronicsItems[i].setName(itemName);

        cout << "Enter total amount for Electronics item " << i + 1 << ": ";
        cin >> electronicsAmount;
        electronicsItems[i].setTotalAmount(electronicsAmount);
    }

    // Accept input for the details of each sports item
    for (int i = 0; i < numSports; ++i) {
        string itemName;
        int sportsAmount;

        cout << "Enter name for Sports item " << i + 1 << ": ";
        cin >> itemName;
        sportsItems[i].setName(itemName);

        cout << "Enter total amount for Sports item " << i + 1 << ": ";
        cin >> sportsAmount;
        sportsItems[i].setTotalAmount(sportsAmount);
    }

    // Calculate the total amount using friend function and print the result
    int total = 0;
    for (int i = 0; i < numElectronics; ++i) {
        for (int j = 0; j < numSports; ++j) {
            if (electronicsItems[i].name == sportsItems[j].name) {
                total += getTotalAmount(electronicsItems[i], sportsItems[j]);
                break;
            }
        }
    }

    cout << "Total amount of Electronics and Sports items: " << total << endl;

    return 0;
}

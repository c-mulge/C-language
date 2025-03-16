#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Rectangle
{
    int len;
    int bred;
};

int main()
{
    Rectangle *p; // in c++ we can skip the struct keyword

    p = new Rectangle; // for c++ we can allocate a memory using new keyword

    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    // to create memory in heap  (it is used in c language)
    cout << "Enter the len and breadth: ";
    cin >> p->len >> p->bred;
    // p->len = 10;
    // p->bred = 20;

    cout << p->len << endl;
    cout << p->bred << endl;
    return 0;
}
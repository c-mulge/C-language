#include <iostream>
using namespace std;

struct node
{
    int len;
    int bred;
};

void initialize(struct node *p, int l, int b)
{
    p->len = l;
    p->bred = b;
}

int area(struct node p)
{
    return p.len * p.bred;
}

void change(struct node *p, int l)
{
    p->len = l;
}

int main()
{
    struct node p;
    initialize(&p, 10, 20);
    area(p);
    change(&p, 20);
    return 0;
}
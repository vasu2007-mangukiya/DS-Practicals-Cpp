#include <iostream>
using namespace std;

void value(int x)
{
    x = x + 10;
    cout << "Call by value: " << x << endl;
}

void reference(int &x)
{
    x = x + 10;
    cout << "Call by reference: " << x << endl;
}

int main()
{
    int a = 5, b = 5;

    value(a);
    cout << "Original a: " << a << endl;

    reference(b);
    cout << "Original b: " << b;

    return 0;
}
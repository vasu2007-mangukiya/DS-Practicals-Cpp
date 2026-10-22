#include <iostream>
using namespace std;

int a[5], top = -1;

void push(int x)
{
    if (top == 4)
        cout << "Stack Overflow\n";
    else
        a[++top] = x;
}

void pop()
{
    if (top == -1)
        cout << "Stack Underflow\n";
    else
        cout << "Deleted: " << a[top--] << endl;
}

void peek()
{
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Top: " << a[top] << endl;
}

void display()
{
    for (int i = top; i >= 0; i--)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();
    peek();
    pop();
    display();

    return 0;
}
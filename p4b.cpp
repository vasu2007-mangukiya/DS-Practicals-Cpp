#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    string exp;

    cout << "Enter postfix: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        if (c >= '0' && c <= '9')
            s.push(c - '0');
        else
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            if (c == '+')
                s.push(a + b);
            if (c == '-')
                s.push(a - b);
            if (c == '*')
                s.push(a * b);
            if (c == '/')
                s.push(a / b);
        }
    }

    cout << "Result: " << s.top();
    return 0;
}
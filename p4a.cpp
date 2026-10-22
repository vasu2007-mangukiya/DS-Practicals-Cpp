#include <iostream>
#include <stack>
using namespace std;

int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int main()
{
    stack<char> s;
    string exp;

    cout << "Enter infix: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        if (isalnum(c))
            cout << c;
        else if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
        else
        {
            while (!s.empty() && s.top() != '(' &&
                   priority(s.top()) >= priority(c))
            {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}
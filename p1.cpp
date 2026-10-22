#include <iostream>
using namespace std;

int main()
{
    int a[100], n, i, pos, val, key;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter position and value to insert: ";
    cin >> pos >> val;

    for (i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = val;
    n++;

    cout << "After insertion: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nEnter position to delete: ";
    cin >> pos;

    for (i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;

    cout << "After deletion: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nEnter value to search: ";
    cin >> key;

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            cout << "Found at position " << i + 1;
            break;
        }
    }

    if (i == n)
        cout << "Not found";

    cout << "\nTraversal: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
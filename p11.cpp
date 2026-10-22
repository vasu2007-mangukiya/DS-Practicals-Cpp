#include <iostream>
using namespace std;

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int key, low = 0, high = 4, mid;

    cout << "Enter element to search: ";
    cin >> key;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            cout << "Element found at position " << mid + 1;
            return 0;
        }
        else if (key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Element not found";

    return 0;
}
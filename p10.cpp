#include <iostream>
using namespace std;

int main()
{
    int a[5] = {50, 20, 40, 10, 30};
    int b[5];

    for (int i = 0; i < 5; i++)
        b[i] = a[i];

    // Bubble Sort
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    cout << "Bubble Sort: ";
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";

    // Selection Sort
    for (int i = 0; i < 4; i++)
    {
        int min = i;

        for (int j = i + 1; j < 5; j++)
        {
            if (b[j] < b[min])
                min = j;
        }

        int t = b[i];
        b[i] = b[min];
        b[min] = t;
    }

    cout << "\nSelection Sort: ";
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";

    return 0;
}
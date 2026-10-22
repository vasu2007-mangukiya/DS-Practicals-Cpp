#include <iostream>
using namespace std;

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;

    for (int i = 4; i >= 0; i--)
        cout << *(p + i) << " ";

    return 0;
}
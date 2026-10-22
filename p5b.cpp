#include <iostream>
using namespace std;

int q[5], front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % 5 == front)
    {
        cout << "Queue Full\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % 5;
    q[rear] = x;
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue Empty\n";
        return;
    }

    cout << "Deleted: " << q[front] << endl;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % 5;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue Empty\n";
        return;
    }

    int i = front;
    while (true)
    {
        cout << q[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % 5;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();

    return 0;
}
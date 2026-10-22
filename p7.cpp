#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void insertBegin(int x)
{
    Node *n = new Node{x, NULL};

    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    Node *t = head;
    while (t->next != head)
        t = t->next;

    n->next = head;
    t->next = n;
    head = n;
}

void insertEnd(int x)
{
    Node *n = new Node{x, NULL};

    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    Node *t = head;
    while (t->next != head)
        t = t->next;

    t->next = n;
    n->next = head;
}

void insertAfter(int key, int x)
{
    if (head == NULL)
        return;

    Node *t = head;
    do
    {
        if (t->data == key)
        {
            Node *n = new Node{x, t->next};
            t->next = n;
            return;
        }
        t = t->next;
    } while (t != head);

    cout << "Node not found\n";
}

void deleteFirst()
{
    if (head == NULL)
        return;

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *t = head;
    while (t->next != head)
        t = t->next;

    Node *d = head;
    head = head->next;
    t->next = head;
    delete d;
}

void deleteLast()
{
    if (head == NULL)
        return;

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *t = head;
    while (t->next->next != head)
        t = t->next;

    delete t->next;
    t->next = head;
}

void deleteAfter(int key)
{
    if (head == NULL)
        return;

    Node *t = head;
    do
    {
        if (t->data == key)
        {
            Node *d = t->next;

            if (d == head && d == t)
            {
                delete d;
                head = NULL;
                return;
            }

            if (d == head)
                head = head->next;

            t->next = d->next;
            delete d;
            return;
        }
        t = t->next;
    } while (t != head);

    cout << "Node not found\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *t = head;
    do
    {
        cout << t->data << " -> ";
        t = t->next;
    } while (t != head);

    cout << "(back to head)\n";
}

int main()
{
    insertBegin(20);
    insertBegin(10);
    insertEnd(40);
    insertAfter(20, 30);
    display();

    deleteFirst();
    display();

    deleteLast();
    display();

    insertEnd(50);
    deleteAfter(20);
    display();

    return 0;
}
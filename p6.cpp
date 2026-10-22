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
    Node *n = new Node{x, head};
    head = n;
}

void insertEnd(int x)
{
    Node *n = new Node{x, NULL};

    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = n;
}

void insertAfter(int key, int x)
{
    Node *t = head;

    while (t != NULL && t->data != key)
        t = t->next;

    if (t == NULL)
    {
        cout << "Node not found\n";
        return;
    }

    Node *n = new Node{x, t->next};
    t->next = n;
}

void deleteFirst()
{
    if (head == NULL)
        return;

    Node *t = head;
    head = head->next;
    delete t;
}

void deleteLast()
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *t = head;
    while (t->next->next != NULL)
        t = t->next;

    delete t->next;
    t->next = NULL;
}

void deleteAfter(int key)
{
    Node *t = head;

    while (t != NULL && t->data != key)
        t = t->next;

    if (t == NULL || t->next == NULL)
    {
        cout << "Node not found or no next node\n";
        return;
    }

    Node *d = t->next;
    t->next = d->next;
    delete d;
}

void display()
{
    Node *t = head;

    while (t != NULL)
    {
        cout << t->data << " -> ";
        t = t->next;
    }

    cout << "NULL\n";
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

    insertEnd(40);
    deleteAfter(20);
    display();

    return 0;
}
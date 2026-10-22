#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *insert(Node *root, int x)
{
    if (root == NULL)
    {
        Node *n = new Node{x, NULL, NULL};
        return n;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void inorder(Node *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
}

void preorder(Node *r)
{
    if (r != NULL)
    {
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(Node *r)
{
    if (r != NULL)
    {
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
}

int main()
{
    Node *root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, a[i]);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}
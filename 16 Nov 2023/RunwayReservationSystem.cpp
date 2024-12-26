#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class BST
{
public:
    long long data;
    BST *right;
    BST *left;
    BST(long long value)
    {
        this->data = value;
        this->right = nullptr;
        this->left = nullptr;
    }
};


BST *insert(BST * &current, long long value)
{
    if (current == nullptr)
    {
        return new BST(value);
    }

    if (value < current->data)
    {
        current->left = insert(current->left, value);
    }
    else if (value > current->data)
    {
        current->right = insert(current->right, value);
    }

    return current;
}

bool check(BST * &current, long long value)
{
    if (current == nullptr)
    {
        return true;
    }

    if (value < current->data-3)
    {
        return check(current->left, value);
    }
    else if (value > current->data + 3)
    {
        return check(current->right, value);
    }

    return false;
}
void printReservations(BST *current)
{
    if (current != nullptr)
    {
        printReservations(current->left);
        cout << current->data << " ";
        printReservations(current->right);
    }
}

int main()
{
    BST *root = nullptr;

    long long reservation;
    while (true)
    {
        cin >> reservation;
        if (reservation == -1)
        {
            break;
        }

        if (check(root, reservation))
        {
            root = insert(root, reservation);
            printReservations(root);
            cout << endl;
        }
        else
        {
            printReservations(root);
            cout << "Reservation failed\n";
        }
    }

    return 0;
}

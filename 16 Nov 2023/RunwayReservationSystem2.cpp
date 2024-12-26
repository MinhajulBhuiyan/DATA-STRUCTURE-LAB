#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int key)
    {
        val = key;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key);
    }
    else
    {
        if (root->val < key)
        {
            root->right = insert(root->right, key);
        }
        else
        {
            root->left = insert(root->left, key);
        }
    }
    return root;
}

void inOrder(Node *root, vector<int> &result)
{
    if (root)
    {
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
}

bool isPossible(Node *root, int key)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->val >= key - 3 && root->val <= key + 3)
    {
        return false;
    }

    if (root->val < key)
    {
        return isPossible(root->right, key);
    }

    return isPossible(root->left, key);
}

void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        cout << current->val << " ";
        q.pop();

        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = root->right;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main()
{
    Node *root = nullptr;
    int numQueries;

    int currentReservations;
    while (true)
    {
        cin >> currentReservations;
        if (currentReservations == -1)
        {
            break;
        }

        root = insert(root, currentReservations);
    }

    cin >> numQueries;

    levelOrderTraversal(root);
    cout << "(initial)" << endl;

    for (int i = 0; i < numQueries; ++i)
    {
        int timestamp;
        cin >> timestamp;

        root = deleteNode(root, timestamp);

        levelOrderTraversal(root);
        cout << endl;
    }

    return 0;
}

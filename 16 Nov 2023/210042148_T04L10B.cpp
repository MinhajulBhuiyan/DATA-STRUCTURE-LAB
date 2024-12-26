#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

int height(Node *node)
{
    return (node == nullptr) ? 0 : node->height;
}

int getBalance(Node *node)
{
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root; // Duplicate keys not allowed
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *findLCA(Node *root, int n1, int n2)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->key > max(n1, n2))
    {
        return findLCA(root->left, n1, n2);
    }
    else if (root->key < min(n1, n2))
    {
        return findLCA(root->right, n1, n2);
    }

    return root;
}

void printInorder(Node *root)
{
    if (root != nullptr)
    {
        printInorder(root->left);
        cout << root->key << " ";
        printInorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;

    int num;
    while (true)
    {
        cin >> num;
        if (num == -1)
        {
            break;
        }

        root = insert(root, num);
    }

    cout << "Status: ";
    printInorder(root);
    cout << endl;

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;

        Node *lca = findLCA(root, n1, n2);

        if (lca != nullptr)
        {
            cout << "LCA of " << n1 << " & " << n2 << ": " << lca->key << endl;
        }
        else
        {
            cout << "Nodes not found in the tree." << endl;
        }
    }

    return 0;
}

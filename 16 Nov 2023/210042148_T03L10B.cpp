#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree 
{
private:
    struct Node 
    {
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int value) : data(value), left(nullptr), right(nullptr), height(0) {}
    };

    Node* root;

    int height(Node* node) 
    {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalanceFactor(Node* node) 
    {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) 
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) 
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + std::max(height(x->left), height(x->right));
        y->height = 1 + std::max(height(y->left), height(y->right));

        return y;
    }

    Node* insertNode(Node* node, int value) 
    {
        if (node == nullptr) return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);
        else
            return node; 

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalanceFactor(node);

        if (balance > 1 && value < node->left->data) 
            return rightRotate(node);

        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->data) { 
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(Node* node) 
    {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << "(" << node->height << ") ";
            inorderTraversal(node->right);
        }
    }

    
public:
    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    int second_largest()
    {
        Node *cur=root;
        while(cur->right->right!=NULL)
            cur=cur->right;
        int ans1=cur->data;
        int ans2=0;
        if(cur->right->left!=nullptr)
        {
            ans2=cur->right->left->data;
        }

        return max(ans1,ans2);
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    AVLTree tree;
    int n;
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        tree.insert(n);
    }

    int ans=tree.second_largest();
    cout<<ans<<"\n";

    cout<<"Status: ";
    tree.inorderTraversal();
}
#include <iostream>

using namespace std;

class LinkedList
{
private:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode() : val(0), next(nullptr) {}
        LinkedNode(int x) : val(x), next(nullptr) {}
    };

    LinkedNode *HEAD;

public:
    LinkedList()
    {
        HEAD = nullptr;
    }

    void Insert_front(int key)
    {
        LinkedNode *newNode = new LinkedNode(key);
        newNode->next = HEAD;
        HEAD = newNode;
    }

    void Insert_back(int key)
    {
        LinkedNode *newNode = new LinkedNode(key);
        if (HEAD == nullptr)
        {
            HEAD = newNode;
        }
        else
        {
            LinkedNode *temp = HEAD;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void Insert_after_node(int key, int v)
    {
        LinkedNode *temp = HEAD;
        while (temp != nullptr)
        {
            if (temp->val == v)
            {
                LinkedNode *newNode = new LinkedNode(key);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found" << endl;
    }

    void Update_node(int key, int v)
    {
        LinkedNode *temp = HEAD;
        while (temp != nullptr)
        {
            if (temp->val == v)
            {
                temp->val = key;
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found" << endl;
    }

    void Remove_head()
    {
        if (HEAD != nullptr)
        {
            LinkedNode *temp = HEAD;
            HEAD = HEAD->next;
            delete temp;
        }
    }

    void Remove_element(int key)
    {
        if (HEAD == nullptr)
        {
            cout << "Empty List" << endl;
            return;
        }
        if (HEAD->val == key)
        {
            Remove_head();
            return;
        }
        LinkedNode *prev = nullptr;
        LinkedNode *curr = HEAD;
        while (curr != nullptr)
        {
            if (curr->val == key)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Node not found" << endl;
    }

    void Remove_end()
    {
        if (HEAD == nullptr)
        {
            cout << "Empty List" << endl;
            return;
        }
        if (HEAD->next == nullptr)
        {
            Remove_head();
            return;
        }
        LinkedNode *prev = nullptr;
        LinkedNode *curr = HEAD;
        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        delete curr;
    }

    void print()
    {
        if (HEAD == nullptr)
        {
            cout << "Empty List" << endl;
            return;
        }
        LinkedNode *temp = HEAD;
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList mLinkedList;

    while (true)
    {
        cout << "Press 1 to insert at front" << endl;
        cout << "Press 2 to insert at back" << endl;
        cout << "Press 3 to insert after a node" << endl;
        cout << "Press 4 to update a node" << endl;
        cout << "Press 5 to remove the first node" << endl;
        cout << "Press 6 to remove a node" << endl;
        cout << "Press 7 to remove the last node" << endl;
        cout << "Press 8 to exit" << endl;

        int command;
        cin >> command;

        if (command == 8)
        {
            break;
        }

        else if (command == 1)
        {
            int key;
            cout << "Enter the key: ";
            cin >> key;
            mLinkedList.Insert_front(key);
            mLinkedList.print();
        }

        else if (command == 2)
        {
            int key;
            cout << "Enter the key: ";
            cin >> key;
            mLinkedList.Insert_back(key);
            mLinkedList.print();
        }

        else if (command == 3)
        {
            int key, v;
            cout << "Enter the key: ";
            cin >> key;
            cout << "Enter the value: ";
            cin >> v;
            mLinkedList.Insert_after_node(key, v);
            mLinkedList.print();
        }

        else if (command == 4)
        {
            int key, v;
            cout << "Enter the key: ";
            cin >> key;
            cout << "Enter the value: ";
            cin >> v;
            mLinkedList.Update_node(key, v);
            mLinkedList.print();
        }

        else if (command == 5)
        {
            mLinkedList.Remove_head();
            mLinkedList.print();
        }

        else if (command == 6)
        {
            int key;
            cout << "Enter the key: ";
            cin >> key;
            mLinkedList.Remove_element(key);
            mLinkedList.print();
        }

        else if (command == 7)
        {
            mLinkedList.Remove_end();
            mLinkedList.print();
        }
    }

    return 0;
}
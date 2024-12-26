#include <iostream>
using namespace std;

struct DoublyLinkedNode
{
    int data;
    DoublyLinkedNode *next;
    DoublyLinkedNode *prev;

    DoublyLinkedNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    DoublyLinkedNode *HEAD;
    DoublyLinkedNode *TAIL;

public:
    DoublyLinkedList() : HEAD(nullptr), TAIL(nullptr) {}

    void Insert_front(int key)
    {
        DoublyLinkedNode *newNode = new DoublyLinkedNode(key);
        if (!HEAD)
        {
            HEAD = TAIL = newNode;
        }
        else
        {
            newNode->next = HEAD;
            HEAD->prev = newNode;
            HEAD = newNode;
        }
        print();
    }

    void Remove_end()
    {
        if (!TAIL)
            return;

        DoublyLinkedNode *temp = TAIL;
        TAIL = TAIL->prev;

        if (TAIL)
            TAIL->next = nullptr;
        else
            HEAD = nullptr;

        delete temp;
        print();
    }

    void print()
    {
        DoublyLinkedNode *current = HEAD;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;

        current = TAIL;
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.Insert_front(5);
    list.Insert_front(10);
    list.Insert_front(3);
    list.Insert_front(7);

    list.Remove_end();
    list.Remove_end();

    return 0;
}

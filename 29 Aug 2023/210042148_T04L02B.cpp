#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

void removeDuplicates(ListNode *head)
{
    if (!head)
        return;

    ListNode *current = head;

    while (current->next)
    {
        if (current->val == current->next->val)
        {
            ListNode *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
}

void printList(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    int num;
    cin >> num;

    while (num != -1)
    {
        ListNode *newNode = new ListNode(num);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> num;
    }

    removeDuplicates(head);
    printList(head);

    // Clean up memory
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

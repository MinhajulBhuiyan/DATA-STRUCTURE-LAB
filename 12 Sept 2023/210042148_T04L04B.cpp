#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
private:
    queue<int> q1; // Main queue
    queue<int> q2; // Temporary queue

public:
    void push(int x)
    {
        q2.push(x); // Add the new element to the temporary queue

        // Move elements from the main queue to the temporary queue
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of the queues to make q2 the new main queue
        swap(q1, q2);
    }

    int pop()
    {
        int topElement = top();
        q1.pop(); // Remove the top element from the main queue
        return topElement;
    }

    int top()
    {
        return q1.front(); // Return the front element of the main queue (top of the stack)
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack myStack;

    myStack.push(10);
    cout << myStack.top() << endl;
    myStack.push(20);
    cout << myStack.top() << endl;
    myStack.pop();
    cout << myStack.top() << endl;
    myStack.push(100);
    cout << myStack.top() << endl;
    cout << myStack.empty() << endl;
    myStack.pop();
    myStack.pop();
    cout << myStack.empty() << endl;

    return 0;
}


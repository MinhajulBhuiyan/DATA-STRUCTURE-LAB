
#include <iostream>

using namespace std;

class mystack
{
public:
    int *arr;
    int top;
    int capacity;

    mystack(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->top = -1;
    }

    void push(int key)
    {
        if (top == capacity - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        top++;
        arr[top] = key;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        top--;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (top == capacity - 1)
        {
            return true;
        }
        return false;
    }

    int getSize()
    {
        return top + 1;
    }

    int topValue()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void print()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int N;
    cin >> N;
    mystack s(N);

    while (true)
    {
        int functionId;
        cin >> functionId;

        if (functionId == -1)
        {
            break; // Stop taking input when -1 is encountered
        }
        else if (functionId == 1)
        {
            int element;
            cin >> element;
            s.push(element); // Push the element onto the stack
            s.print();
        }
        else if (functionId == 2)
        {
            s.pop(); // Pop an element from the stack
            s.print();
        }
        else if (functionId == 3)
        {
            bool result = s.isEmpty();
            cout << (result ? "True" : "False") << endl; // Check if the stack is empty
        }
        else if (functionId == 4)
        {
            bool result = s.isFull();
            cout << (result ? "True" : "False") << endl; // Check if the stack is full
        }
        else if (functionId == 5)
        {
            int result = s.getSize(); // Get the current size of the stack
            cout << result << endl;
        }
        else if (functionId == 6)
        {
            int result = s.topValue(); // Get the top element of the stack
            cout << result << endl;
        }
    }

    return 0;
}
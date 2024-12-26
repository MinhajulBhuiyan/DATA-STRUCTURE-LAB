#include <iostream>
using namespace std;

class DoubleEndedQueue
{
private:
    int arr[100];
    int front;
    int rear;
    int size;

public:
    DoubleEndedQueue()
    {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == 100; // Check if the size has reached the maximum
    }

    void pushLeft(int x)
    {
        if (isFull())
        {
            cout << "The queue is full" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                front = (front - 1 + 100) % 100;
            }
            arr[front] = x;
            size++;
            cout << "Pushed in left: " << x << endl;
        }
    }

    void pushRight(int x)
    {
        if (isFull())
        {
            cout << "The queue is full" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % 100;
            }
            arr[rear] = x;
            size++;
            cout << "Pushed in right: " << x << endl;
        }
    }

    void popLeft()
    {
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
        }
        else
        {
            cout << "Popped from left: " << arr[front] << endl;
            front = (front + 1) % 100;
            size--;
        }
    }

    void popRight()
    {
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
        }
        else
        {
            cout << "Popped from right: " << arr[rear] << endl;
            rear = (rear - 1 + 100) % 100;
            size--;
        }
    }
};

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int n, m;
        cin >> n >> m;

        DoubleEndedQueue dq;
        cout << "Case " << t << ":" << endl;

        for (int i = 0; i < m; i++)
        {
            string command;
            cin >> command;

            if (command == "pushLeft")
            {
                int x;
                cin >> x;
                dq.pushLeft(x);
            }
            else if (command == "pushRight")
            {
                int x;
                cin >> x;
                dq.pushRight(x);
            }
            else if (command == "popLeft")
            {
                dq.popLeft();
            }
            else if (command == "popRight")
            {
                dq.popRight();
            }
        }
    }

    return 0;
}

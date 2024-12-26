#include <iostream>

const int maxSize = 5; // Change the size as needed

class CircularQueue
{
private:
    int arr[maxSize];
    int front;
    int rear;

public:
    CircularQueue()
    {
        front = rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return (rear + 1) % maxSize == front;
    }

    // Function to get the current size of the queue
    int size()
    {
        if (isEmpty())
        {
            return 0;
        }

        else if (rear >= front)
        {
            return (rear - front + 1);
        }

        return (maxSize - front + rear + 1);
    }

    // Function to enqueue an element
    void Enqueue(int x)
    {
        if (isFull())
        {
            std::cout << "Queue is full. Cannot enqueue " << x << std::endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize;
        }

        arr[rear] = x;
    }

    // Function to dequeue an element
    int Dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Return a default value to indicate an error
        }

        int removedValue = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % maxSize;
        }

        return removedValue;
    }

    // Function to get the front element
    int frontValue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. No front element." << std::endl;
            return -1; // Return a default value to indicate an error
        }

        return arr[front];
    }

    // Function to get the rear element
    int rearValue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. No rear element." << std::endl;
            return -1; // Return a default value to indicate an error
        }

        return arr[rear];
    }
};

int main()
{
    CircularQueue queue;

    std::cout << "Enqueue 1 to 5:" << std::endl;
    for (int i = 1; i <= 5; ++i)
    {
        queue.Enqueue(i);
    }

    std::cout << "Front element: " << queue.frontValue() << std::endl;
    std::cout << "Rear element: " << queue.rearValue() << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    std::cout << "Dequeue 3 elements:" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        int val = queue.Dequeue();
        std::cout << "Dequeued: " << val << std::endl;
    }

    std::cout << "Queue is empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Queue is full? " << (queue.isFull() ? "Yes" : "No") << std::endl;

    return 0;
}

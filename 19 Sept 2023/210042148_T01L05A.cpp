#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    int parent(int index)
    {
        return index/2;
    }

    int leftChild(int index)
    {
        return 2 * index;
    }

    int rightChild(int index)
    {
        return 2 * index + 1;
    }

    void heapifyUp(int index)
    {
        while (index > 1 && heap[parent(index)] > heap[index])
        {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index)
    {
        int minIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] <= heap[minIndex])
        {
            minIndex = left;
        }

        if (right < heap.size() && heap[right] < heap[minIndex])
        {
            minIndex = right;
        }

        if (index != minIndex)
        {
            swap(heap[index], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size());
    }

    int extractMin()
    {
        if (heap.empty())
        {
            return -1;
        }

        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return min;
    }

    int getMin()
    {
        if (heap.empty())
        {
            return -1;
        }
        return heap[0];
    }

    void decreaseKey(int p, int k)
    {
        if (p >= heap.size())
        {
            cout << ("Index out of bounds");
        }

        heap[p] -= k;
        heapifyUp(p);
    }

    void increaseKey(int p, int k)
    {
        if (p >= heap.size())
        {
            cout << ("Index out of bounds");
        }

        heap[p] += k;
        heapifyDown(p);
    }

    bool isEmpty()
    {
        return heap.empty();
    }

    void printHeap()
    {
        for (int value : heap)
        {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main()
{
    MinHeap minHeap;

    int num;
    while (true)
    {
        cin >> num;
        if (num == -1)
        {
            break;
        }
        minHeap.insert(num);
    }

    while (true)
    {
        int function_id;
        cin >> function_id;

        if (function_id == 1)
        {
            // Heap_Minimum
            cout << minHeap.getMin() << endl;
        }
        else if (function_id == 2)
        {
            // Heap_extract_min
            int min = minHeap.extractMin();
            cout << min << endl;
        }
        else if (function_id == 3)
        {
            // Min_heap_insert
            int value;
            cin >> value;
            minHeap.insert(value);
        }
        else if (function_id == 4)
        {
            // Heap_decrease_key
            int p, k;
            cin >> p >> k;
            minHeap.decreaseKey(p, k);
        }
        else if (function_id == 5)
        {
            // Heap_increase_key
            int p, k;
            cin >> p >> k;
            minHeap.increaseKey(p, k);
        }

        minHeap.printHeap();
    }

    return 0;
}

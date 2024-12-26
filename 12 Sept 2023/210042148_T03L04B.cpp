#include <iostream>
#include <queue>
using namespace std;

class RecentCounter
{
private:
    queue<int> requests;

public:
    int ping(int t)
    {
        // Add the new request timestamp to the queue
        requests.push(t);

        // Remove timestamps that are outside the 3000 ms window
        while (!requests.empty() && requests.front() < t - 3000)
        {
            requests.pop();
        }

        // Return the size of the queue (number of requests in the window)
        return requests.size();
    }
};

int main()
{
    RecentCounter counter;

    cout << counter.ping(1) << "\n";
    cout << counter.ping(2) << "\n";
    cout << counter.ping(3) << "\n";
    cout << counter.ping(4) << "\n";
    cout << counter.ping(3001) << "\n";
    cout << counter.ping(3002) << "\n";
    cout << counter.ping(3003) << "\n";
    cout << counter.ping(6003) << "\n";
    cout << counter.ping(10003) << "\n";

    return 0;
}

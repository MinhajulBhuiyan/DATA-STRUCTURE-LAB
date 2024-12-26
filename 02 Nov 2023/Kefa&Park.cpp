#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 100005;

vector<int> adjacency[MAX_NODES];
int restaurantCount, totalNodes, catStatus[MAX_NODES], maxConsecutiveCats;

void exploreTree(int currentNode, int consecutiveCats, int parent)
{
    if (catStatus[currentNode])
        consecutiveCats++;
    else
        consecutiveCats = 0;

    if (consecutiveCats > maxConsecutiveCats)
        return;

    if (adjacency[currentNode].size() == 1 && currentNode != 1)
    {
        if (consecutiveCats <= maxConsecutiveCats)
            restaurantCount++;
        return;
    }

    for (int nextNode : adjacency[currentNode])
    {
        if (nextNode != parent)
        {
            exploreTree(nextNode, consecutiveCats, currentNode);
        }
    }
}

int main()
{
    cin >> totalNodes >> maxConsecutiveCats;

    for (int i = 1; i <= totalNodes; i++)
        cin >> catStatus[i];

    for (int i = 1; i < totalNodes; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        adjacency[nodeA].push_back(nodeB);
        adjacency[nodeB].push_back(nodeA);
    }

    exploreTree(1, 0, 0);

    cout << restaurantCount;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    vector<vector<int>> adjList(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << "List view:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] + 1 << " ";
        }
        cout << endl;
    }

    cout << "Matrix view:" << endl;
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

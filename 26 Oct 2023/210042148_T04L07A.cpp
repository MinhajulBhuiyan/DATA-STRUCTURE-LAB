#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Graph
{
public:
    int n;
    vector<vector<int>> adj;

    Graph(int n)
    {
        this->n = n;
        adj.resize(n);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, vector<bool> &visited, set<int> &component)
    {
        visited[node] = true;
        component.insert(node);

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, visited, component);
            }
        }
    }

    vector<set<int>> findConnectedComponents()
    {
        vector<set<int>> components;
        vector<bool> visited(n, false);

        for (int node = 0; node < n; node++)
        {
            if (!visited[node])
            {
                set<int> component;
                dfs(node, visited, component);
                components.push_back(component);
            }
        }

        return components;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u - 1, v - 1); // Decrement by 1 to match 0-based indexing.
    }

    vector<set<int>> components = graph.findConnectedComponents();

    cout << "Components: " << components.size() << endl;
    cout << "Component sets:" << endl;
    for (set<int> component : components)
    {
        cout << "{";
        for (int node : component)
        {
            cout << node + 1; // Increment by 1 for 1-based indexing.
            if (node != *(--component.end()))
            {
                cout << " ";
            }
        }
        cout << "}" << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class DSU
{
public:
    vector<int> parent;

    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; 
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            parent[y] = x;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu.unite(u - 1, v - 1); 
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (dsu.find(x - 1) == dsu.find(y - 1))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}

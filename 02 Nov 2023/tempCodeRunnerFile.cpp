#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const long long INF = 1e15;

long long distances[N][N];

void floydWarshall(int n)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            distances[i][j] = INF;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        distances[a][b] = min(distances[a][b], c);
        distances[b][a] = min(distances[b][a], c);
    }

    floydWarshall(n);

    int u, q;
    cin >> u >> q;

    while (q--)
    {
        int v;
        cin >> v;

        if (distances[u][v] != INF)
        {
            cout << distances[u][v] << endl;
        }
        else
        {
            cout << "NO PATH" << endl;
        }
    }

    return 0;
}

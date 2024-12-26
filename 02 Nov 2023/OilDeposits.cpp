#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_M = 100;
const int MAX_N = 100;

int m, n;
char grid[MAX_M][MAX_N];
bool visited[MAX_M][MAX_N];

// Define possible neighbor directions (horizontally, vertically, and diagonally)
int dr[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dc[] = {0, 0, 1, -1, 1, -1, -1, 1};

// Function to perform BFS to explore the oil deposit
void bfs(int r, int c)
{
    visited[r][c] = true;
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty())
    {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nr = curR + dr[i];
            int nc = curC + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] == '@')
            {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int countOilDeposits()
{
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && grid[i][j] == '@')
            {
                count++;
                bfs(i, j);
            }
        }
    }

    return count;
}

int main()
{
    while (cin >> m >> n && m > 0)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                visited[i][j] = false;
            }
        }

        int result = countOilDeposits();
        cout << result << endl;
    }

    return 0;
}

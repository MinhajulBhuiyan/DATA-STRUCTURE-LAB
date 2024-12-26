#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int case_num = 1; case_num <= t; case_num++)
    {
        int n;
        cin >> n;

        unordered_map<int, int> rivalry_count;
        vector<int> fighters;

        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            fighters.push_back(u);
            fighters.push_back(v);
        }

        int max_rivals = 0;
        for (int fighter : fighters)
        {
            int count = ++rivalry_count[fighter];
            max_rivals = max(max_rivals, count);
        }

        cout << "Case " << case_num << ": " << max_rivals << endl;
    }

    return 0;
}

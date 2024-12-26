#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N = 1e5;
const int INF = 1e9 + 10;

int main()
{
	//  freopen("input.txt", "r", stdin);
	//  freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	stack<pair<int, int>> stk;
	int x, mx = 0, i, j;

	while (1)
	{
		cin >> x;
		if (x == -1)
			break;
		v.push_back(x);
		mx = max(mx, x);
	}

	vector<int> ans(v.size());
	stk.push({v[0], 0});

	for (i = 0; i < v.size(); i++)
	{
		while (!stk.empty() && stk.top().first < v[i])
		{
			ans[stk.top().second] = v[i];
			stk.pop();
		}
		if (v[i] == mx)
			ans[i] = -1;
		else
			stk.push({v[i], i});
	}
	for (i = 0; i < v.size(); i++)
	{
		while (!stk.empty() && stk.top().first < v[i])
		{
			ans[stk.top().second] = v[i];
			stk.pop();
		}
	}

	for (auto e : ans)
		cout << e << " ";
	cout << "\n";

	return 0;
}

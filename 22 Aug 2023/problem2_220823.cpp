#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr first
#define sc second
vector<int>vis(200000), pos(200000), cnt(200000);

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	int tst, n, i, targt;
	
	cin >> n >> targt;
	vector<int> v(n);
	for(i = 0; i < n; i++){
		cin >> v[i];
		pos[v[i]] = i;
		cnt[v[i]]++;
	}
	
	bool flg = true;
	int p = 0;
	for(auto e : v){
		if(!vis[e] && e < targt && cnt[e] && 2 * e != targt && cnt[targt - e]){
			p += cnt[e] * cnt[targt - e];
			if(flg) cout << pos[e] << " " << pos[targt- e] << "\n";
			flg = false;
			vis[targt-e] = 1;
		}
		vis[e] = 1;
	}
	cout << p << "\n";
		
	return 0;
}
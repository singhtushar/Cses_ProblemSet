#include <bits/stdc++.h>
#define  FAST   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define  el     "\n"
#define  all(v) v.begin(),v.end()
#define  pb     push_back
#define  vi     vector<int>
#define  int    long long
using namespace std;

vector<int> adj[100001];
vector<bool> vis(100001, false);
vector<int> team(100001);

bool dfs(int node, int x = 1) {
	vis[node] = true;
	team[node] = x;
	for (int it : adj[node]) {
		if (!vis[it]) {
			if (dfs(it, x ^ 1) == false)
				return false;
		}
		else if (team[it] == team[node])
			return false;
	}
	return true;
}

int32_t main() {
	FAST;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// check it graph is Bipartite or not!!
	bool fl = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			fl &= dfs(i);
		}
	}
	if (!fl)
		cout << "IMPOSSIBLE" << el;
	else {
		for (int i = 1; i <= n; i++) {
			if (team[i] == 0)
				cout << 2 << ' ';
			else
				cout << team[i] << ' ';
		}
		cout << el;
	}
	return 0;
}

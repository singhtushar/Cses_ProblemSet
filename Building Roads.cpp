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

void dfs(int node) {
	vis[node] = true;
	for (int it : adj[node]) {
		if (!vis[it])
			dfs(it);
	}
}

int32_t main() {
	FAST;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}
	int cnt = 0;
	vi roads;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			roads.pb(i);
			dfs(i);
			cnt++;
		}
	}
	cout << cnt - 1 << el;
	for (int i = 1; i < roads.size(); i++) {
		cout << roads[i - 1] << ' ' << roads[i] << el;
	}
	return 0;
}

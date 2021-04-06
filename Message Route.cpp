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

void bfs(int src, int n, int m) {
	vector<int> dist(n + 1, 1e7);
	vector<int> par(n + 1);
	dist[src] = 0;
	par[src] = -1;
	queue<pair<int, int>> q;
	q.push({src, 0});
	while (!q.empty()) {
		int node = q.front().first;
		int len = q.front().second;
		q.pop();
		for (int it : adj[node]) {
			if (!vis[it]) {
				vis[it] = true;
				q.push({it, len + 1});
				if (dist[it] > len + 1) {
					dist[it] = len + 1;
					par[it] = node;
				}
			}
		}
	}
	if (vis[n] == false)
		cout << "IMPOSSIBLE\n";
	else {
		vi path;
		int node = n;
		while (node != -1) {
			path.pb(node);
			node = par[node];
		}
		reverse(all(path));
		cout << path.size() << el;
		for (int x : path)
			cout << x << ' ';
		cout << el;
	}
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
	bfs(1, n, m);
	return 0;
}

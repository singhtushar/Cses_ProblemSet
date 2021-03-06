#include <bits/stdc++.h>
#define  FAST   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define  el     "\n"
#define  all(v) v.begin(),v.end()
#define  pb     push_back
#define  vi     vector<int>
#define  int    long long
using namespace std;

vector<int> adj[100001];
bool vis[100001];
int parent[100001];

int startPt, endPt;

bool checkCycle(int node, int par = -1) {
	vis[node] = true;
	parent[node] = par;
	for (auto it : adj[node]) {
		if (!vis[it]) {
			if (checkCycle(it, node))
				return true;
		}
		else if (it != par) {
			startPt = it;
			endPt = node;
			return true;
		}
	}
	return false;
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
	int src = -1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (checkCycle(i)) {
				src = i;
				break;
			}
		}
	}
	if (src == -1)
		cout << "IMPOSSIBLE" << el;
	else {
		vi path;
		path.pb(startPt);
		int node = endPt;
		while (node != startPt) {
			path.pb(node);
			node = parent[node];
		}
		path.pb(startPt);
		cout << path.size() << el;
		for (int x : path)
			cout << x << ' ';
		cout << el;
	}
	return 0;
}

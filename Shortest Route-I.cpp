#include <bits/stdc++.h>
#define  FAST   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define  el     "\n"
#define  all(v) v.begin(),v.end()
#define  pb     push_back
#define  vi     vector<int>
#define  pii    pair<int,int>
#define  int    long long
using namespace std;

const int N = 2e5 + 5;
vector<pii> adj[N];
bool vis[N];
vector<int> dist(N, 1e18);

void dijkstra(int src) {
	dist[src] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, src});
	while (!pq.empty()) {
		int node = pq.top().second;
		int dis = pq.top().first;
		pq.pop();
		if (vis[node]) continue;
		vis[node] = true;
		for (auto it : adj[node]) {
			int child = it.first, wt = it.second;
			if (!vis[child] && dist[child] > dis + wt) {
				pq.push({dis + wt, child});
				dist[child] = dis + wt;
			}
		}
	}

}

int32_t main() {
	FAST;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v, wt});
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
	cout << el;
	return 0;
}

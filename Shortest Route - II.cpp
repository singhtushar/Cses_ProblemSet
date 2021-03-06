#include <bits/stdc++.h>
#define  FAST   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define  el     "\n"
#define  all(v) v.begin(),v.end()
#define  pb     push_back
#define  vi     vector<int>
#define  int    long long
using namespace std;

const int INF = 1e18;

int32_t main() {
	FAST;
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> g(n + 1, vector<int>(n + 1, INF));
	vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; i++) {
		int a, b, wt;
		cin >> a >> b >> wt;
		--a, --b;
		d[a][a] = 0, d[b][b] = 0;
		g[a][b] = wt;
		g[b][a] = wt;
		d[a][b] = min(d[a][b], wt);
		d[b][a] = min(d[b][a], wt);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][k] == INF || d[k][j] == INF) continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		cout << ((d[u][v] == INF) ? -1 : d[u][v]) << el;
	}
	return 0;
}

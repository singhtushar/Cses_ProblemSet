#include <bits/stdc++.h>
#define  FAST   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define  el     "\n"
#define  all(v) v.begin(),v.end()
#define  pb     push_back
#define  vi     vector<int>
#define  int    long long
using namespace std;

const int INF = 1e18;
struct Edge
{
	int a;
	int b;
	int wt;
};

int32_t main() {
	FAST;
	int n, m;
	cin >> n >> m;
	// egde list
	vector<Edge> g(m);
	for (int i = 0; i < m; i++) {
		cin >> g[i].a >> g[i].b >> g[i].wt;
	}

	vector<int> d(n + 1); // since the graph may be disconnected d[i]=0
	vector<int> p(n + 1, -1);
	int x = -1;
	for (int i = 0; i <= n; i++) {
		x = -1;
		for (auto e : g) {
			if (d[e.b] > d[e.a] + e.wt) {
				d[e.b] = d[e.a] + e.wt;
				p[e.b] = e.a;
				x = e.b;
			}
		}
	}

	if (x == -1)
		cout << "NO" << el;
	else {
		cout << "YES" << el;

		// to enter into the negative cycle
		for (int i = 0; i < n; i++) {
			x = p[x];
		}

		vector<int> cycle;
		cycle.pb(x);
		int node = p[x];
		while (node != x) {
			cycle.pb(node);
			node = p[node];
		}
		cycle.pb(node);
		reverse(all(cycle));
		for (int x : cycle)
			cout << x << ' ';
		cout << el;
	}
	return 0;
}

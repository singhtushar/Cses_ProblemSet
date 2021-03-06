#include <bits/stdc++.h>
#define  FAST   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define  el     "\n"
#define  all(v) v.begin(),v.end()
#define  pb     push_back
#define  vi     vector<int>
#define  int    long long
using namespace std;

/*

Modified Bellman Ford Algorithm for Negative Cycle

-> BF returns SSSP in V*E operations incase of no negative cycle.
-> Otherwise, BF resolves Negative Cycles SSSP in 2*V*E operations 
   with negative cycle.
-> Time Complexity: O(V*E)   

*/

const int INF = 1e18;

struct Edge
{
	int a;
	int b;
	int wt;
};

vector<int> d(100001, INF);
vector<int> p(100001, -1);

int32_t main() {
	FAST;
	int n, m;
	cin >> n >> m;
	vector<Edge> g(m);
	for (int i = 0; i < m; i++) {
		cin >> g[i].a >> g[i].b >> g[i].wt;
		g[i].wt = -1 * g[i].wt;
	}

	d[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (auto e : g) {
			if (d[e.a] < INF && d[e.b] > d[e.a] + e.wt) {
				d[e.b] = max(-INF, d[e.a] + e.wt);
				p[e.b] = e.a;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (auto e : g) {
			if (d[e.a] < INF && d[e.b] > d[e.a] + e.wt) {
				d[e.b] = -INF;
				p[e.b] = e.a;
			}
		}
	}

	if (d[n] == -INF) {
		cout << -1 << el;
	}
	else
		cout << -1 * (d[n]) << el;
	return 0;
}

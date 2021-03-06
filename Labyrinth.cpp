#include <bits/stdc++.h>
#define  FAST   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define  el     "\n"
#define  all(v) v.begin(),v.end()
#define  pb     push_back
#define  pii    pair<int,int>
#define  vi     vector<int>
#define  ff     first
#define  ss     second
#define  int    long long
using namespace std;

const int dx[] = { -1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

bool isValid(int newi, int newj, vector<vector<bool>>& vis, vector<string>& a, int n, int m) {
	return (newi >= 0 && newj >= 0 && newi < n && newj < m
	        && !vis[newi][newj] && (a[newi][newj] == '.' || a[newi][newj] == 'B'));
}

int32_t main() {
	FAST;
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (auto &x : a)
		cin >> x;
	pair<int, int> src, des;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'A')
				src = {i, j};
			if (a[i][j] == 'B')
				des = {i, j};
		}
	}
	string res = "";
	vector<vector<int>> distance(n + 1, vector<int>(m + 1, 1e7));
	vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
	pair<int, int> parent[n + 1][m + 1];
	parent[src.ff][src.ss] = { -1, -1};
	distance[src.ff][src.ss] = 0;
	queue<pair<pii, int>> q;
	q.push({{src.ff, src.ss}, 0});
	while (!q.empty()) {
		int x = q.front().ff.ff;
		int y = q.front().ff.ss;
		int dist = q.front().ss;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newi = x + dx[i];
			int newj = y + dy[i];
			if (isValid(newi, newj, vis, a, n, m)) {
				q.push({{newi, newj}, dist + 1});
				vis[newi][newj] = true;
				distance[newi][newj] = dist + 1;
				parent[newi][newj] = {x, y};
				if (a[newi][newj] == 'B')
					break;
			}
		}
	}

	if (vis[des.ff][des.ss] == 0)
		cout << "NO" << el;
	else {
		cout << "YES" << el;
		cout << distance[des.ff][des.ss] << el;
		int i = des.ff, j = des.ss;
		vector<pii> path;
		while (i != -1 && j != -1) {
			path.pb({i, j});
			int x = i, y = j;
			i = parent[x][y].ff;
			j = parent[x][y].ss;
		}
		reverse(all(path));
		int sz = path.size();
		for (int i = 0; i < sz - 1; i++) {
			int i1 = path[i].ff, j1 = path[i].ss;
			int i2 = path[i + 1].ff, j2 = path[i + 1].ss;
			if (i1 - 1 == i2)
				res += 'U';
			else if (i1 + 1 == i2)
				res += 'D';
			else if (j1 - 1 == j2)
				res += 'L';
			else
				res += 'R';
		}
		cout << res << el;
	}
	return 0;
}

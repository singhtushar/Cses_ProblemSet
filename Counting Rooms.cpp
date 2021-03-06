#include <bits/stdc++.h>
#define  FAST   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define  el     "\n"
#define  all(v) v.begin(),v.end()
#define  pb     push_back
#define  vi     vector<int>
#define  int    long long

using namespace std;

const int dx[] = { -1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, vector<string>& a, int n, int m, vector<vector<bool>>& vis) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int newi = x + dx[i];
		int newj = y + dy[i];
		if (newi >= 0 && newi < n && newj >= 0 && newj < m 
			&& !vis[newi][newj] && a[newi][newj] == '.') {

			dfs(newi, newj, a, n, m, vis);
		
		}
	}
}

int32_t main() {
	FAST;
	int n, m;
	cin >> n >> m;
	vector<string> a;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a.pb(s);
	}

	vector<vector<bool>> vis(n, vector<bool>(m, false));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && a[i][j] == '.') {
				dfs(i, j, a, n, m, vis);
				cnt++;
			}
		}
	}
	cout << cnt << el;
	return 0;
}

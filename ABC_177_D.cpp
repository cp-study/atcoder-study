#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
using namespace std;
typedef long long ll;

void dfs(int curr, vector<vector<int>>& v,
	vector<bool>& visited, int &cnt) {
	if (visited[curr]) return;
	visited[curr] = true;
	cnt++;
	for (int i = 0; i < v[curr].size(); i++) {
		dfs(v[curr][i], v, visited, cnt);
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<bool> visited(N + 1);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		dfs(i, v, visited, cnt);
		ans = max(ans, cnt);
	}

	cout << ans << endl;
}
